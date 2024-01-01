#include <bits/stdc++.h>

using namespace std;
#define ln '\n'
typedef long long ll;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ll mod = 1e9 + 7;
    ll n{};
    cin >> n;

    if ((n * (n + 1)) % 4 != 0) {
        cout << "0" << ln;
    } else {
        vector<vector<ll>> dp_table(n, vector<ll>((n * (n + 1) / 4) + 1));
        dp_table[0][0] = 1;
        for (int y = 0; y < dp_table.size(); y++) {
            // cout << y << ": ";
            for (int x = 0; x <= (n * (n + 1) / 4); x++) {
                if (y > 0) {
                    dp_table[y][x] = dp_table[y - 1][x] % mod;
                    if (x >= y && dp_table[y - 1][x - y]) dp_table[y][x] += dp_table[y - 1][x - y] % mod;
                }
                // cout << dp_table[y][x] << " ";
            }
            // cout << ln;
        }
        cout << dp_table.back().back() % mod << ln;
    }
}
/*
This one I had a little more trouble with :((. It's just the knapsack problem, ur finding all the possible
ways of adding up to half the set (or 0 if not possible), where different permutations don't count.

Mistakes:
- Did not add the edge case where it's not possible
- Put += 1 instead of += dp_table[y - 1][x - y]. No idea how that happened. Silly mistake but took a long
while to figure this out. D:


*/