// #include <bits/stdc++.h>
// using namespace std;

// // Helper function to count "XMAS" in a specific direction
// int countWord(vector<string>& grid, int x, int y, int dx, int dy, const string& word) {
//     int count = 0, n = grid.size(), m = grid[0].size();
//     int len = word.size();
//     for (int i = 0; i < len; i++) {
//         int nx = x + i * dx, ny = y + i * dy;
//         if (nx < 0 || nx >= n || ny < 0 || ny >= m || grid[nx][ny] != word[i]) {
//             return 0;
//         }
//     }
//     return 1; // If the entire word matches
// }

// int main() {
//     vector<string> grid = {
//         "MMMSXXMASM",
//         "MSAMXMSMSA",
//         "AMXSXMAAMM",
//         "MSAMASMSMX",
//         "XMASAMXAMM",
//         "XXAMMXXAMA",
//         "SMSMSASXSS",
//         "SAXAMASAAA",
//         "MAMMMXMMMM",
//         "MXMXAXMASX"
//     };

//     string word = "XMAS";
//     int n = grid.size(), m = grid[0].size();
//     int count = 0;

//     // Directions: (dx, dy)
//     vector<pair<int, int>> directions = {
//         {0, 1},   // Right
//         {1, 0},   // Down
//         {1, 1},   // Down-Right (Main Diagonal)
//         {1, -1},  // Down-Left (Anti-Diagonal)
//         {0, -1},  // Left
//         {-1, 0},  // Up
//         {-1, -1}, // Up-Left
//         {-1, 1}   // Up-Right
//     };

//     // Traverse each cell
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             // Check all directions for the word "XMAS"
//             for (auto [dx, dy] : directions) {
//                 count += countWord(grid, i, j, dx, dy, word);
//             }
//         }
//     }

//     cout << "The word 'XMAS' appears " << count << " times." << endl;

//     return 0;
// }
