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
        string s;
        cin>>s;
        string temp=s;
        reverse(s.begin(),s.end());
        if(temp==s){
            bool flag=false;
            int i=1;
            while(flag==false && i<temp.size()){
                if(temp[i]!=temp[0]){
                    swap(temp[i],temp[0]);
                    flag=true;
                }
                i++;
            }
            if(flag==true){
                cout<<temp<<endl;
            }
            else{
                cout<<-1<<endl;
            }
        }
        else{
            cout<<temp<<endl;
        }
    }
}