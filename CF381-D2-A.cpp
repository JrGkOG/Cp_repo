#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    deque<int>nums;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        nums.push_back(x);
    }
    bool flag=false;
    int sr=0;
    int dima=0;
    while(!nums.empty()){
        if(flag==false){
            flag=!flag;
            int f=nums.front();
            int b=nums.back();
            if(b>f){
                sr+=b;
                nums.pop_back();
            }
            else{
                sr+=f;
                nums.pop_front();
            }
        }   
        else{
            flag=!flag;
            int f=nums.front();
            int b=nums.back();
            if(b>f){
                dima+=b;
                nums.pop_back();
            }
            else{
                dima+=f;
                nums.pop_front();
            }
        }
    }
    cout<<sr<<" "<<dima;
}