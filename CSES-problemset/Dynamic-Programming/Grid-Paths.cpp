#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    // freopen("input.txt", "r", stdin);

    int n{};
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n));

    int mod = 1e9 + 7;
    grid[0][0] = 1;

    for (vector<int>& row : grid) {
        for (int& x : row) {
            char temp{};
            cin >> temp;
            if (temp == '*') x = -1;
        }
    }

    // for (vector<int>& row : grid) {
    //     for (int& x : row) {
    //         cout << x << ' ';
    //     }
    //     cout << endl;
    // }

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            if ((y > 0) && (grid[y - 1][x] != -1) && (grid[y][x] != -1)) {
                grid[y][x] += grid[y - 1][x] % mod;
            }
            if ((x > 0) && (grid[y][x - 1] != -1) && (grid[y][x] != -1)) {
                grid[y][x] += grid[y][x - 1] % mod;
            }
            // cout << grid[y][x] << " ";
        }
        // cout << endl;
    }

    if (grid.back().back() == -1)
        cout << 0 << endl;
    else
        cout << grid.back().back() % mod << endl;
}

/*
- Correct 2nd try because I didn't flail around trial and error-ing it, but looked at the edge cases I missed and corrected them easily.

Mistakes:
- Remembered to check the top and left for traps, but forgot to check self for trap. This means it overwrites self before the check can trigger.
- Should have set grid[0][0] to be 1 before grid is filled, for edge case that grid[0][0] is a trap
- Forgot to check if bottom right is trap before output. (If trap it should be 0, not -1)
- YOU STILL FORGOT TO MODULUS THJE OUTPUT YOU FOOL AEJKSDFGHJGSDFHJHJ

*/