#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int calculateSymmetryCost(vector<int> &oddSticks){
    sort(oddSticks.begin(),oddSticks.end());
    int cost=0;
    int oddCount=oddSticks.size();
    if(oddCount>2){
        for(int i=0;i<oddCount-2;++i){
            cost+=oddSticks[i];
        }
    }
    return cost;
}

vector<pair<int,int>> getGroups(map<int,int> &freqMap){
    vector<pair<int,int>> groups;
    for(auto &pr:freqMap){
        groups.push_back(make_pair(pr.first,pr.second));
    }
    sort(groups.rbegin(),groups.rend());
    return groups;
}

vector<int> getOddSticks(vector<pair<int,int>> &groups){
    vector<int> oddSticks;
    for(auto &pr:groups){
        if(pr.second%2!=0) oddSticks.push_back(pr.first);
    }
    return oddSticks;
}

int computeAnswer(int totalSum,int totalCount,vector<pair<int,int>> &groups,vector<int> &oddSticks){
    int symmetryCost=calculateSymmetryCost(oddSticks);
    int curSum=totalSum;
    int curCount=totalCount;
    int idx=0;
    int oddCount=oddSticks.size();
    int ans=0;
    while(true){
        int S=curSum-symmetryCost;
        int maxLen=(idx<groups.size()?groups[idx].first:0);
        int remCount=curCount-(oddCount>2?oddCount-2:0);
        if(remCount>=3&&S>2*maxLen){
            ans=S;
            break;
        }
        if(idx>=groups.size()) break;
        auto [len,cnt]=groups[idx];
        curSum-=len*cnt;
        curCount-=cnt;
        if(cnt%2==1){
            if(oddCount>2) symmetryCost-=oddSticks[oddCount-3];
            oddCount--;
        }
        idx++;
    }
    return ans;
}

void solve(){
    int n;
    cin>>n;
    map<int,int> freqMap;
    int totalSum=0;
    for(int i=0;i<n;++i){
        int x;
        cin>>x;
        freqMap[x]++;
        totalSum+=x;
    }
    vector<pair<int,int>> groups=getGroups(freqMap);
    vector<int> oddSticks=getOddSticks(groups);
    int ans=computeAnswer(totalSum,n,groups,oddSticks);
    cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
