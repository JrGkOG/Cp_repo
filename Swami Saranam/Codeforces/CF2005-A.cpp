
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
        int n;
        cin>>n;
        string s="aeiou";
        
        int size=5;
        string answerString; 
        if(n<=5){
            int index=0;
            while(n--){
            answerString+=s[index%size];
            index++;
            }
        }
        else{
            int time=n-5;
            int index=0;
            while(time--){
                answerString+="a";
            }
            n-=answerString.size();
            while(n--){
                answerString+=s[index%size];
                index++;
            }
        }
        cout<<answerString<<"\n";
    }
}