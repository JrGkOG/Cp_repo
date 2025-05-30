#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define yes "Yes"
#define no "No"
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);   

void func(){
    int t;
    cin>>t;
    while(t--){
        ll x;
        cin>>x;
        string s;
        cin>>s;
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1') mini=min(mini,i);
            else if(s[i]=='0'  && i<s.size()-1 && s[i+1]=='1') maxi=max(maxi,i); 
        }
        if(mini==INT_MAX) cout<<s.size()<<endl;
        else if(maxi==INT_MIN) cout<<s.size()+1<<endl;
        else if(maxi > mini){
            reverse(s.begin()+mini,s.begin()+maxi+1);
            char prev='0';
            int counter=0;
            for(int i=0;i<s.size();i++){
                if(s[i]==prev) counter++;
                else{
                    counter+=2;
                    prev=s[i];
                }
            }
            cout<<counter<<endl;
        }
        else if (maxi < mini){
            cout<<s.size()+1<<endl;
        }
    }
}
int main(){
    fast();
    func();
    return 0;
}