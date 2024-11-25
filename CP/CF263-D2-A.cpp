#include <iostream>
#include <cstdlib> 
using namespace std;
int main() {
    int grid[5][5];
    int srow, scol;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 1) {
                srow = i; 
                scol = j; 
            }
        }
    }
    int moves = abs(srow - 2) + abs(scol - 2);
    cout << moves << endl;
    return 0;
}
