#include <bits/stdc++.h>

using namespace std;
int calculateTotalDistance(vector<int>& left, vector<int>& right) {

    sort(left.begin(), left.end());
    sort(right.begin(), right.end());
    int totalDistance = 0;
    for (size_t i = 0; i < left.size(); ++i) {
        totalDistance += abs(left[i] - right[i]);
    }
    return totalDistance;
}

int main() {
    ifstream inputFile("input.txt");  
    if (!inputFile) {
        cerr << "Error: Could not open file 'input.txt'." << endl;
        return 1;
    }
    vector<int> left, right;
    int num1, num2;
    while (inputFile >> num1 >> num2) {
        left.push_back(num1);
        right.push_back(num2);
    }
    inputFile.close();
    int totalDistance = calculateTotalDistance(left, right);
    cout << "Total Distance: " << totalDistance << endl;
    return 0;
}
