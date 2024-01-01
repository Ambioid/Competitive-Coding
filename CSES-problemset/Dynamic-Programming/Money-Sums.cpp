#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif


    ll total_coins{};
    cin >> total_coins;

    ll sum{0};
    vector<ll> coins(total_coins);
    for (auto& it : coins) {
        cin >> it;
        sum += it;
    }
    coins.insert(coins.begin(), 0);


    vector<vector<int>> grid(total_coins + 1, vector<int>(sum + 1));

    bool last_row = false;
    ll distinct_sums = 0;
    for (ll y = 0; y < grid.size(); y++) {
        // cout << coins[y] << ": ";
        if (y == total_coins) last_row = true;

        for (ll x = 0; x < grid[0].size(); x++) {
            if (x == 0)
                grid[y][x] = 1;
            else if (y > 0) {
                if (grid[y - 1][x]) {
                    grid[y][x] = 1;
                } else if ((x >= coins[y]) && (grid[y - 1][x - coins[y]])) {
                    grid[y][x] = 1;
                }
            }
            // cout << grid[y][x] << " ";

            if ((last_row) && grid[y][x] && x != 0) {
                distinct_sums++;
            }
        }
        // cout << endl;
    }
    cout << distinct_sums << endl;
    for (ll i = 1; i <= sum; i++) {
        if (grid.back()[i]) cout << i << " ";
    }
    cout << endl;
}

/*
Like I said in the Rectangle-Cutting program, I think I am starting to get a hang of how to do this. I think that's just because at
this point I have seen enough problems that I've seen most the ways these questions can be formulated. So I kinda already know all
the possible ways to solve them. Well mostly. Not 100% yet probably. By reading the statement I could figure out that it was going
to be really similar to the knapsack problem from the way it was formulated, but I had to read a hint by glimpsing at the first line
in the codeforces editorial for this. But after just the hint that you store it as 2d boolean array, I immediately knew how to do it.
My solution worked first try, and with a little fiddling in the code editor. I guess this means I'm nearing more fuller completion
of knowing the basics of DP problems.

Mistakes:
- I took the grid value from the current row (effecively meaing that you kep selecting the same thing repeatedly) instead of just
the current row. Spotted it realy quickly.
*/