#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast()                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);   

int main(){
    fast();
    string c;
    cin>>c;
    if(c.size()<7){
        cout<<"NO";
        return 0;
    }
    else{
        int counterA=0;
        int counterB=0;
        int i=0;
        while(i<c.size()){
            if(c[i]=='0'){
                counterA++;
                counterB=0;
                if(counterA>=7){
                    cout<<"YES";
                    return 0;
                }
            }
            else if(c[i]=='1'){
                counterB+=1;
                counterA=0;
                if(counterB>=7){
                    cout<<"YES";
                    return 0;
                }
            }
            i+=1;
        }
        cout<<"NO";
        return 0;
    }
}