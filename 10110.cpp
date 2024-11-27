#include <bits/stdc++.h>
using namespace std;

int main() {
	 long long n;
	 while(cin>>n&&n)
	 {
		 long long root=sqrt(n);
		 if(root*root==n){
			 cout<<"yes\n";
		 }
		 else
			 cout<<"no\n";
	 }
	return 0;
}