#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int lamik;
    int bob;
    cin>>lamik>>bob;
    int counter=0;
    while(!(lamik>bob)){
        counter++;
        lamik=lamik*3;
        bob=bob*2;
    }
    cout<<counter;
}