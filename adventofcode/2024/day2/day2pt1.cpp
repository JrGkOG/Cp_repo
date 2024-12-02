#include <bits/stdc++.h>
using namespace std;
bool isValidSequence(const vector<int>& array) {
    bool isIncreasing = true, isDecreasing = true;

    for (size_t i = 0; i < array.size() - 1; i++) {
        int diff = abs(array[i] - array[i + 1]);

        if (diff < 1 || diff > 3) { 
            return false;
        }

        if (array[i] < array[i + 1]) {
            isDecreasing = false;  
        } else if (array[i] > array[i + 1]) {
            isIncreasing = false;  
        }
    }
    return isIncreasing || isDecreasing;
}
bool canBeMadeSafe(const vector<int>& array) {
    for (size_t i = 0; i < array.size(); i++) {
        vector<int> modifiedArray = array;
        modifiedArray.erase(modifiedArray.begin() + i);
        if (isValidSequence(modifiedArray)) {
            return true; 
        }
    }
    return false;
}
int main() {
    ifstream inputFile("input.txt"); 
    if (!inputFile.is_open()) {
        cerr << "Error: Could not open file." << endl;
        return 1;
    }
    string line;
    int safeReports = 0; 
    while (getline(inputFile, line)) {
        vector<int> array;
        stringstream ss(line);
        int num;
        while (ss >> num) {
            array.push_back(num);
        }
        if (isValidSequence(array) || canBeMadeSafe(array)) {
            safeReports++;
        }
    }
    inputFile.close();
    cout << safeReports << endl; 

    return 0;
}
