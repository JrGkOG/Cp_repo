#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    string prev="-1";
    int blocks=0;
    for(int i=0;i<n;i++){
        string number;
        cin>>number;
        if(prev=="-1"){
            prev=number;
            blocks+=1;
        }else{
            if(number=="10" && prev=="01"){
                blocks+=1;
                prev=number;
            }
            else if(number=="01" && prev=="10"){
                blocks+=1;
                prev=number;
            }
            else{
                prev=number;
            }
        }
    }
    cout<<blocks;
    return 0;
}