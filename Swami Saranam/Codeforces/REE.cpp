#include <bits/stdc++.h>
using namespace std;

#define M_PI 3.14159265358979323846

enum PointLabel {
    UNLABELED,
    GROUND,
    NON_GROUND
};

struct Point {
    double x,y,z;
    PointLabel label=UNLABELED;
};

// Coarse ground segmentation using Radial Elevation Estimation (REE)
void coarseSegmentationREE(vector<Point>&a,double et=0.2,double rmax=70.0,double da=0.4,double dr=0.2) {
    int m=360.0/da,n=rmax/dr;
    // grid[r][θ] stores point indices falling in that polar bin
    vector<vector<vector<int>>>grid(n,vector<vector<int>>(m));
    
    // Map points into polar grid
    for(int i=0;i<a.size();i++) {
        Point&p=a[i];
        double r=sqrt(p.x*p.x+p.y*p.y);
        if(r>=rmax)continue;
        double theta=atan2(p.y,p.x)*180.0/M_PI;
        if(theta<0)theta+=360.0;
        int ri=r/dr,ti=theta/da;
        if(ri<n&&ti<m)grid[ri][ti].push_back(i);
    }

    // For each azimuth sector
    for(int j=0;j<m;j++) {
        double prev=1e18; // prev min ground elevation
        for(int i=0;i<n;i++) {
            double zmin=1e18;
            // find min z in current cell
            for(int idx:grid[i][j])zmin=min(zmin,a[idx].z);
            // elevation thresholding
            double curr=i==0?zmin:min(prev+et,zmin);
            for(int idx:grid[i][j]) {
                if(a[idx].z>=curr+et)a[idx].label=NON_GROUND;
                else a[idx].label=GROUND;
            }
            prev=curr;
        }
    }
}

// Test code
int main() {
    vector<Point>a;
    srand(time(0));
    // flat ground generation
    for(int i=0;i<30;i++) {
        for(int j=-15;j<15;j++) {
            double z=0.05*((rand()%10)/10.0-0.5);
            a.push_back({(double)i,(double)j,z});
        }
    }
    // wall generation
    for(int j=-5;j<5;j++) {
        for(int k=0;k<8;k++) {
            a.push_back({15.0,(double)j,(double)k*0.5+0.5});
        }
    }

    cout<<"Original point cloud size: "<<a.size()<<endl;
    coarseSegmentationREE(a);

    int g=0,ng=0,ul=0;
    for(auto&p:a) {
        if(p.label==GROUND)g++;
        else if(p.label==NON_GROUND)ng++;
        else ul++;
    }

    cout<<"\n--- Segmentation Results ---\n";
    cout<<"Ground points: "<<g<<endl;
    cout<<"Non-ground points: "<<ng<<endl;
    cout<<"Unlabeled points: "<<ul<<" (outside Rmax)"<<endl;
    return 0;
}
