#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int nums;
    cin>>nums;
    vector<int>nums2;
    for(int i=0;i<nums;i++){
        int m,a,b,c;
        cin>>m>>a>>b>>c;
        int totalSeated=2*m;
        int seated=0;
        seated+=min(m,a);
        seated+=min(m,b);
        if(seated<totalSeated){
            int aval=totalSeated-seated;
            seated+=min(c,aval);
        }
        nums2.push_back(seated);
    }
    for(int i=0;i<nums2.size();i++){
        cout<<nums2[i]<<"\n";
    }
    return 0;
}