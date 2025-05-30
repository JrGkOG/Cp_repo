#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define yes "Yes"
#define no "No"
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

void func()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
        {
            cin >> nums[i];
        }
        vector<pair<int, int>> adj[n + 1];
        for (int i = 0; i < m; i++)
        {
            ll x, y, wt;
            cin >> x >> y >> wt;
            adj[x].push_back({y, wt});
        }
        vector<int> dis(n, INT_MAX);
        priority_queue<
            pair<int, pair<int, int>>,         // The type of elements (a pair of int and pair<int, int>)
            vector<pair<int, pair<int, int>>>, // The underlying container (a vector)
            greater<pair<int, pair<int, int>>> // The comparator (min-heap)
            >
            pq;
        pq.push({INT_MAX,{nums[0],1}});
        int mini=INT_MAX;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int currMini=it.first;
            int batt=it.second.first;
            int node=it.second.second;
            for(auto itr:adj[node]){
                int wt=itr.second;
                int adjNode=itr.first;
                if(wt>batt) continue;
                batt+=nums[adjNode];
                if( mini < max(currMini,wt )){
                    mini=max(currMini,wt);
                    pq.push({mini,{batt,adjNode}});
                }
            }
        }   
        if(mini==INT_MAX){
            cout<<-1<<endl;
        }else{
            cout<<mini<<endl;
        }
        binary_search(nums.begin(),nums.end(),7);
    }
}
int main()
{
    fast();
    func();
    return 0;
}