#include <bits/stdc++.h>
using namespace std;

// Function to check if a sequence is safe
bool isSafe(const vector<int>& array) {
    for (size_t i = 0; i < array.size() - 1; i++) {
        int diff = abs(array[i] - array[i + 1]);
        // If difference is greater than 3 or 0, it's unsafe
        if (diff > 3 || diff == 0) {
            return false;
        }
    }
    return true;
}

// Function to check if a sequence can be made safe by removing one level
bool canBeMadeSafe(const vector<int>& array) {
    // Try removing each level one by one
    for (size_t i = 0; i < array.size(); i++) {
        vector<int> modifiedArray = array;
        modifiedArray.erase(modifiedArray.begin() + i);

        // Check if the modified array is safe
        if (isSafe(modifiedArray)) {
            return true;
        }
    }
    return false;
}

int main() {
    ifstream inputFile("input.txt"); // Open the file for reading
    if (!inputFile.is_open()) {
        cerr << "Error: Could not open file." << endl;
        return 1;
    }

    string line;
    int safeReports = 0; // Total count of safe reports

    while (getline(inputFile, line)) {
        vector<int> array;
        stringstream ss(line);
        int num;

        // Read the numbers in the current line
        while (ss >> num) {
            array.push_back(num);
        }

        // Check if the report is safe or can be made safe by removing one level
        if (isSafe(array) || canBeMadeSafe(array)) {
            safeReports++;
        }
    }

    inputFile.close();

    cout << safeReports << endl; // Output the number of safe reports

    return 0;
}
