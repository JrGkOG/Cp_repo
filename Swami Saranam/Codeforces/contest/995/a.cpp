#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
int main() {
    fast();
    int t;
    cin >> t;
    vector<int>anss;
    while (t--) {
        int number;
        cin >> number;
        vector<int> nums1(number);
        vector<int> nums2(number);

        for (int i = 0; i < number; i++) {
            cin >> nums1[i];
        }
        for (int i = 0; i < number; i++) {
            cin >> nums2[i];
        }

        int sum = 0;
        for (int i = 0; i < nums1.size()-1; i++) {
            if(nums1[i]-nums2[i+1]>0){
                sum+=nums1[i]-nums2[i+1];
            }
        }
        sum+=nums1[nums1.size()-1];
        anss.push_back(sum);
    }
    for(int i=0;i<anss.size();i++){
        cout<<anss[i]<<endl;
    }
    return 0;
}