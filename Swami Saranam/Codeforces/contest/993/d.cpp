#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main() {
    int t;
    cin >> t;
    while (t--) {
        int t2;
        cin >> t2;
        set<int> st;
        vector<int> nums(t2);
        set<int> notThere;
        for (int i = 1; i <= t2; i++) {
            notThere.insert(i);
        }
        for (int i = 0; i < t2; i++) {
            cin >> nums[i];
            st.insert(nums[i]);
            if (notThere.find(nums[i]) != notThere.end()) {
                notThere.erase(nums[i]);
            }
        }
        vector<int> ans;
        for (int i = 0; i < t2; i++) {
            if (st.find(nums[i]) != st.end()) {
                ans.push_back(nums[i]);
                st.erase(nums[i]);  
            } else {
                ans.push_back(*notThere.begin()); 
                notThere.erase(notThere.begin()); 
            }
        }
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
