#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);   

int main(){
    fast();
    int t;
    cin>>t;
    while(t--){
        int length;
        cin>>length;
        string s;
        cin>>s;
        int t=0;
        int minNumber=0;
        int maxNumber=0;
        for(int i=0;i<length;i++){
            if(s[i]=='>'){
                t-=1;
                minNumber=min(minNumber,t);
            }
            else{
                t+=1;
                maxNumber=max(maxNumber,t);
            }
        }
        // 0<1<2>1<2>1>0>-1>-2< -1< 0 < 1>0
        if(minNumber!=0){
            minNumber=abs(minNumber)+1;
            cout<<minNumber+maxNumber<<"\n";
        }
        else{
            cout<<maxNumber+1<<"\n";
        }
        
    }
    return 0;
}