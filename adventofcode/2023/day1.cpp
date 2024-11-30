#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        cerr << "Error: Unable to open input.txt" << endl;
        return 1;
    }
    deque<int> dq; 
    string line;
    int sum=0;
    while (getline(inputFile, line)) {
        for (char ch : line) { 
            if (isdigit(ch)) { 
                dq.push_back(ch - '0'); 
            }
        }
        int first=dq.front();
        int second=dq.back();
        // cout<<first<<second;
        while(!dq.empty()){
            dq.pop_back();
        }
        sum+=(first*10)+second;
    }
    cout<<sum;
}
