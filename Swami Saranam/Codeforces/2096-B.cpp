#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define yes "Yes"
#define no "No"
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);   
void printArr(vector<int>arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void func(){
    int t;
    cin>>t;
    while(t--){
        ll x,y;
        cin>>x>>y;
        vector<int>nums1(x);
        vector<int>nums2(x);
        int total1=0;
        int total2=0;
        for(int i=0;i<x;i++){
            cin>>nums1[i];
            total1+=nums1[i];
        }
        for(int i=0;i<x;i++){
            cin>>nums2[i];
            total2+=nums2[i];
        }
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        reverse(nums1.begin(),nums1.end());
        reverse(nums2.begin(),nums2.end());
        cout<<total1<<" "<<total2<<endl;
        printArr(nums1);
        printArr(nums2);
        int finalAns=0;
        if(total1 > total2 ){
            finalAns+=total1;
            int i=0;
            while(i < y ){
                finalAns+=nums2[i];
                i+=1;
            }
        }
        else if (total2 > total1){
            finalAns+=total2;
            int i=0;
            while(i < y ){
                finalAns+=nums1[i];
                i+=1;
            }
        }
        else{
            int temp=0;
            int temp2=0;
            int i=0;
            while(i < y ){
                temp+=nums2[i];
                temp2+=nums1[i];
                i+=1;
            }
            finalAns+=max(temp,temp2);
        }
        cout<<finalAns<<endl;
    }
}
int main(){
    fast();
    func();
    return 0;
}