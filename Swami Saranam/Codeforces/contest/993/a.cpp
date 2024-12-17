#include <bits/stdc++.h>
using namespace std;
#define ll long long 


int main(){
    int number;
    cin>>number;
    vector<int>array;
    for(int i=0;i<number;i++){
        int num;
        cin>>num;
        int counter=0;
        for(int i=1;i<num;i++){
            for(int j=1;j<num;j++){
                if(i+j==num){
                    counter++;
                }
            }
        }
        array.push_back(counter);
    }
    for(int i=0;i<array.size();i++){
        cout<<array[i]<<"\n";
    }
    return 0;
}