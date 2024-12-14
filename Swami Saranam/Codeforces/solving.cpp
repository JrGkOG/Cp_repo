#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int f1(int n){
    if(n==1){
        return 1;
    }
    else{
        return n*n + f1(n-1);
    }
}
int f2(int n){
    int sum=0;
    for(int i=n;i>=1;i--){
        sum+=(i*(i+1))/2;
    }
    return sum;
}
double f3(double x){
    double sum=0;
    for(double i=1;i<=x;i++){
        sum+=i;
        if(i>10){
            sum+=(i+1)/100;
        }
        else {
            sum+=(i+1)/10;
        }
    }
    return sum;
}
int f4(int x){
    int digit=0;
    int sum=0;
    for(int i=0;i<x;i++){
        int temp=pow(10,i)*9+digit;
        cout<<temp<<"\n";
        digit=temp;
        sum+=digit;
    }
    return sum;
}
int binomialCoeff(int n, int k) {
    int res = 1;
    if (k > n - k)
        k = n - k;
    for (int i = 0; i < k; ++i) {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}
vector<vector<int>> printPascal(int n) {
    vector<vector<int>> mat;
    for (int row = 0; row < n; row++) {
        vector<int> arr;
        for (int i = 0; i <= row; i++)
            arr.push_back(binomialCoeff(row, i));
        mat.push_back(arr);
    }
    return mat;
}
int main(){
    cout<<f1(5)<<"\n";
    cout<<f2(5)<<"\n";
    cout<<f3(10)<<"\n";
    cout<<f4(5)<<"\n";
    int n = 5;
    vector<vector<int>> mat = printPascal(n);
    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[i].size(); j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}