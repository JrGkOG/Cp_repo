#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);   
void performAction(vector<vector<ll>> &grid, unordered_map<ll, pair<ll, ll>> &mp)
{
    ll rows = grid.size();
    ll cols = grid[0].size();
    for (ll i = 0; i < rows; i++)
    {
        for (ll j = 0; j < cols; j++)
        {
            ll delRow[] = {-1, 0, 1, 0};
            ll delCol[] = {0, 1, 0, -1};
            ll totalRows = grid.size();
            ll totalCols = grid[0].size();
            ll curr = grid[i][j];
            for (ll p = 0; p < 4; p++)
            {
                ll nRow = i + delRow[p];
                ll nCol = j + delCol[p];
                if (nRow >= 0 && nCol >= 0 && nRow < totalRows && nCol < totalCols && grid[nRow][nCol] == curr)
                {
                    if(mp.find(curr)!=mp.end()){
                        if(mp[curr].second!=0) mp[curr].second--;
                    }
                }
            }
        }
    }
    ll maxi=INT_MIN;
    ll node=INT_MIN;
    for(auto it:mp){
        if((it.second.first-it.second.second)>maxi){
            maxi=it.second.first-it.second.second;
            node=it.first;
        }
    }
    ll answer=0;
    for(auto it:mp){
        if(it.first!=node){
            if(it.second.second!=0){
                answer+=1+(it.second.first-it.second.second);
            }
            else{
                answer+=it.second.first;
            }
        }
    }
    cout<<answer<<endl;
}

void func(){
    fast();
    int t;  
    cin>>t;
    while(t--){
        ll m,n;
        cin>>m>>n;
        vector<vector<ll>>matrix(m,vector<ll>(n));
        unordered_map<ll,pair<ll,ll>>mp;
        for(ll i=0;i<m;i++){
            for(ll j=0;j<n;j++){
                ll number;
                cin>>number;
                matrix[i][j]=number;
                mp[number].first++;
                mp[number].second++;
            }
        }
        performAction(matrix,mp);
    }
}
int main(){
    func();
    return 0;
}