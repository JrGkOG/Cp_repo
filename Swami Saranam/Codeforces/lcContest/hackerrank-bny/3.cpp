#include<bits/stdc++.h>

using namespace std;

unordered_map<string, int> prefixMap;

void insertPrefixes(const string& s) {
    string prefix = "";
    for (char ch : s) {
        prefix += ch;
        prefixMap[prefix]++; 
    }
}

int queryPrefix(const string& s) {
    return prefixMap.count(s) ? prefixMap[s] : 0;
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        string func, name;
        cin >> func >> name;
        if(func == "add") {
            insertPrefixes(name);
        } else if(func == "find") {
            cout << queryPrefix(name) << endl;
        }
    }
}
