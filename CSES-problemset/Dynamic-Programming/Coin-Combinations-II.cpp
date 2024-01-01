#include <bits/stdc++.h>

using namespace std;

int main() {
    // freopen("input.txt", "r", stdin);

    int coins_num, sum;
    cin >> coins_num >> sum;

    vector<vector<int>> memo(coins_num, vector<int>(sum + 1, 0));

    vector<int> coins(coins_num);
    for (auto& x : coins) cin >> x;

    cout << endl;
    memo[0][0] = 1;
    int mod = 1e9 + 7;

    for (int y = 0; y < coins_num; y++) {
        for (int x = 0; x < sum + 1; x++) {
            // cout << "coin:" << coins[y] << ":coin" << endl;
            if (x >= coins[y]) {
                memo[y][x] += memo[y][x - coins[y]] % mod;
            }
            if (y > 0) {
                memo[y][x] += memo[y - 1][x] % mod;
            }
            // cout << memo[y][x] << " ";
        }
        // cout << endl;
    }
    cout << memo[coins_num - 1][sum] % mod << endl;
}

/*
Mistakes:
- Used ll instead of int, which caused a runtime error.
- Used modulus calculation on the constructing part, but forgot to do that in the final output.
*/