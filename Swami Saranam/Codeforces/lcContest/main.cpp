#include <bits/stdc++.h>
using namespace std;


int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
    vector<pair<int, int>> sorted;
    int n=baskets.size();
    for (int i = 0; i < n; i++) sorted.push_back({i,baskets[i]});
    sort(sorted.begin(), sorted.end());
    int counter=0;
    for(int i=0;i<fruits.size();i++){
        auto it = lower_bound(sorted.begin(), sorted.end(), make_pair(-1,fruits[i]));
        if (it == sorted.end()) {
            counter++;
        }
        else{
            cout<<fruits[i]<<"fruits"<<endl;
            cout<<(*it).second<<"firs"<<endl;
            sorted.erase(it); 
        }
    }
    return counter;
}



int main(){
    int n;
    cin>>n;
    vector<int>basket(n);
    vector<int>fruits(n);
    for(int i=0;i<n;i++) cin>>fruits[i];
    for(int i=0;i<n;i++) cin>>basket[i];
    return numOfUnplacedFruits(fruits,basket);
}