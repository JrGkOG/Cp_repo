#include <bits/stdc++.h>
using namespace std;

map<int, tuple<string>> parse(const string& data) {
    return {{1, make_tuple(data)}, {2, make_tuple(data)}};
}

int part1(const string& memory) {
    regex pattern("mul\\((\\d{1,3}),(\\d{1,3})\\)");
    sregex_iterator it(memory.begin(), memory.end(), pattern);
    sregex_iterator end;

    int total = 0;
    while (it != end) {
        total += stoi((*it)[1].str()) * stoi((*it)[2].str());
        ++it;
    }
    return total;
}

int part2(const string& memory) {
    regex split_pattern("(don't\\(\\)|do\\(\\))");
    sregex_token_iterator it(memory.begin(), memory.end(), split_pattern, -1);
    sregex_token_iterator end;

    vector<string> memory_segments(it, end);
    int result = part1(memory_segments[0]);

    for (size_t i = 1; i < memory_segments.size(); i += 2) {
        if (memory_segments[i] == "do()") {
            result += part1(memory_segments[i + 1]);
        }
    }
    return result;
}

int main() {
    ifstream input("input.txt");
    if (!input.is_open()) {
        cerr << "Error opening input file." << endl;
        return 1;
    }
    string memory;
    getline(input, memory);
    input.close();
    int result_part1 = part1(memory);
    int result_part2 = part2(memory);
    ofstream output("output.txt");
    if (!output.is_open()) {
        cerr << "Error opening output file." << endl;
        return 1;
    }
    output << "Part 1 Result: " << result_part1 << endl;
    output << "Part 2 Result: " << result_part2 << endl;
    output.close();
    return 0;
}
