#include <bits/stdc++.h>
using namespace std;
int calculateSimilarityScore(const vector<int>& left, const vector<int>& right) {
    unordered_map<int, int> frequencyMap;
    for (int num : right) {
        frequencyMap[num]++;
    }
    int similarityScore = 0;
    for (int num : left) {
        if (frequencyMap.count(num) > 0) {
            similarityScore += num * frequencyMap[num];
        }
    }
    return similarityScore;
}

int main() {
    ifstream inputFile("input.txt");  
    if (!inputFile) {
        return 1;
    }
    vector<int> left, right;
    int num1, num2;
    while (inputFile >> num1 >> num2) {
        left.push_back(num1);
        right.push_back(num2);
    }
    inputFile.close();
    int similarityScore = calculateSimilarityScore(left, right);
    cout << similarityScore << endl;
    return 0;
}
