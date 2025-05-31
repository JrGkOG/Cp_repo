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
        string s1;
        string s2;
        int x;
        cin>>x;
        cin>>s1>>s2;
        int zero=0;
        int one=0;
        for(int i=0;i<x;i++){
            if(s1[i]=='0') zero++;
            else one++;
        }
        if(one == 0 ) cout<<"YES"<<endl;
        else{
            for(int i=0;i<x;i++){
                if(s1[i]=='1'){
                    int j=i-1;
                    bool done=false;
                    while(j>=0 && done==false){
                        if(s2[j] == '0'){
                            s2[j]='1';
                            s1[i]='0';
                            done=true;
                        }
                        else{
                            j-=2;
                        }
                    }
                    if(s1[i]=='1'){
                        j=i+1;
                        done=false;
                        while(j<x && done==false){
                            if(s2[j] == '0'){
                                s2[j]='1';
                                s1[i]='0';
                                done=true;
                            }
                            else{
                                j+=2;
                            }
                        }
                    }
                }
            }
            bool flag=false;
            for(int i=0;i<x;i++){
                if(s1[i]=='1'){
                    flag=true;
                }
            }
            if(flag==true) cout<<"NO"<<endl;
            else{
                cout<<"YES"<<endl;
            }
        }
    }
}
int main(){
    fast();
    func();
    return 0;
}