#include <bits/stdc++.h>
using namespace std;
#define ll long long 

int main() {
    int inputs;
    cin >> inputs;
    vector<int> nums(inputs);
    int minInd = -1;
    int maxInd = -1;
    int minVal = INT_MAX;
    int maxVal = INT_MIN;
    for (int i = 0; i < inputs; i++) {
        cin >> nums[i];
        if (nums[i] < minVal) {
            minVal = nums[i];
            minInd = i;
        }
        if (nums[i] > maxVal) {
            maxVal = nums[i];
            maxInd = i;
        }
    }
    int counter = 0;
    if (minInd < maxInd) {
        maxInd--; 
    }
    for (int i = minInd; i < inputs - 1; i++) {
        swap(nums[i], nums[i + 1]);
        counter++;
    }
    for (int i = maxInd; i > 0; i--) {
        swap(nums[i], nums[i - 1]);
        counter++;
    }
    cout << counter;
    return 0;
}
