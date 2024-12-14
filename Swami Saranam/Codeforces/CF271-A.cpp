#include <bits/stdc++.h>
using namespace std;

bool isUni(int number) {
    unordered_set<int> digitSet; 
    while (number > 0) {
        int digit = number % 10; 
        if (digitSet.count(digit)) {
            return false; 
        }
        digitSet.insert(digit);
        number /= 10; 
    }
    return true; 
}

int main() {
    int number;
    cin >> number;
    do {
        number++; 
    } while (!isUni(number)); 
    cout << number << endl; 
    return 0;
}
