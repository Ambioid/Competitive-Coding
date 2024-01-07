#include <bits/stdc++.h>
#define ln '\n'
using namespace std;

typedef long long ll;

ll is_valid(const vector<vector<ll>>& tiles, vector<vector<ll>>& globally_checked, ll y, ll x, const bool is_player1) {  // Function checks if it is a valid loop.

    bool is_loop = true;
    ll n = tiles.size() - 1;

    ll score = 0;
    set<pair<ll, ll>> locally_checked{};
    queue<pair<ll, ll>> to_check{};
    to_check.push({y, x});
    while (!to_check.empty()) {
        if (y < 0 || y > tiles.size() - 1 || x < 0 || x > tiles.size() - 1) {
            to_check.pop();
            continue;
        }

        y = to_check.front().first;
        x = to_check.front().second;

        if (locally_checked.count(pair<ll, ll>{y, x})) {
            to_check.pop();
            continue;
        }
        score++;
        // ll tile = tiles[y][x];

        // cout << tiles[y][x] << " " << y << " " << x << ln;
        locally_checked.insert(pair<ll, ll>{y, x});
        if (is_player1) {
            if (tiles[y][x] == 1) {
                to_check.push(pair<ll, ll>{y - 1, x});
                to_check.push(pair<ll, ll>{y + 1, x});
                if (y == 0 || (tiles[y - 1][x] != 5 && tiles[y - 1][x] != 6 && tiles[y - 1][x] != 1)) return 0;
                if (y == n || (tiles[y + 1][x] != 3 && tiles[y + 1][x] != 4 && tiles[y + 1][x] != 1)) return 0;
            } else if (tiles[y][x] == 2) {
                to_check.push(pair<ll, ll>{y, x - 1});
                to_check.push(pair<ll, ll>{y, x + 1});
                if (x == 0 || (tiles[y][x - 1] != 4 && tiles[y][x - 1] != 5 && tiles[y][x - 1] != 2)) return 0;
                if (x == n || (tiles[y][x + 1] != 3 && tiles[y][x + 1] != 6 && tiles[y][x + 1] != 2)) return 0;
            } else if (tiles[y][x] == 3) {
                to_check.push(pair<ll, ll>{y, x - 1});
                to_check.push(pair<ll, ll>{y - 1, x});
                if (x == 0 || (tiles[y][x - 1] != 4 && tiles[y][x - 1] != 5 && tiles[y][x - 1] != 2)) return 0;
                if (y == 0 || (tiles[y - 1][x] != 5 && tiles[y - 1][x] != 6 && tiles[y - 1][x] != 1)) return 0;
            } else if (tiles[y][x] == 4) {
                to_check.push(pair<ll, ll>{y, x + 1});
                to_check.push(pair<ll, ll>{y - 1, x});
                if (x == n || (tiles[y][x + 1] != 3 && tiles[y][x + 1] != 6 && tiles[y][x + 1] != 2)) return 0;
                if (y == 0 || (tiles[y - 1][x] != 5 && tiles[y - 1][x] != 6 && tiles[y - 1][x] != 1)) return 0;
            } else if (tiles[y][x] == 5) {
                to_check.push(pair<ll, ll>{y + 1, x});
                to_check.push(pair<ll, ll>{y, x + 1});
                if (y == n || (tiles[y + 1][x] != 3 && tiles[y + 1][x] != 4 && tiles[y + 1][x] != 1)) return 0;
                if (x == n || (tiles[y][x + 1] != 3 && tiles[y][x + 1] != 6 && tiles[y][x + 1] != 2)) return 0;
            } else if (tiles[y][x] == 6) {
                to_check.push(pair<ll, ll>{y + 1, x});
                to_check.push(pair<ll, ll>{y, x - 1});
                if (y == n || (tiles[y + 1][x] != 3 && tiles[y + 1][x] != 4 && tiles[y + 1][x] != 1)) return 0;
                if (x == 0 || (tiles[y][x - 1] != 4 && tiles[y][x - 1] != 5 && tiles[y][x - 1] != 2)) return 0;
            }
            if (globally_checked[y][x] == 0) globally_checked[y][x] = 1;
            if (globally_checked[y][x] == 2) globally_checked[y][x] = 3;
        } else {
            if (tiles[y][x] == 2) {
                to_check.push(pair<ll, ll>{y - 1, x});
                to_check.push(pair<ll, ll>{y + 1, x});
                if (y == 0 || (tiles[y - 1][x] != 2 && tiles[y - 1][x] != 3 && tiles[y - 1][x] != 4)) return 0;
                if (y == n || (tiles[y + 1][x] != 2 && tiles[y + 1][x] != 5 && tiles[y + 1][x] != 6)) return 0;
            } else if (tiles[y][x] == 1) {
                to_check.push(pair<ll, ll>{y, x - 1});
                to_check.push(pair<ll, ll>{y, x + 1});
                if (x == 0 || (tiles[y][x - 1] != 1 && tiles[y][x - 1] != 3 && tiles[y][x - 1] != 6)) return 0;
                if (x == n || (tiles[y][x + 1] != 1 && tiles[y][x + 1] != 4 && tiles[y][x + 1] != 5)) return 0;
            } else if (tiles[y][x] == 5) {
                to_check.push(pair<ll, ll>{y, x - 1});
                to_check.push(pair<ll, ll>{y - 1, x});
                if (x == 0 || (tiles[y][x - 1] != 1 && tiles[y][x - 1] != 3 && tiles[y][x - 1] != 6)) return 0;
                if (y == 0 || (tiles[y - 1][x] != 2 && tiles[y - 1][x] != 3 && tiles[y - 1][x] != 4)) return 0;
            } else if (tiles[y][x] == 6) {
                to_check.push(pair<ll, ll>{y, x + 1});
                to_check.push(pair<ll, ll>{y - 1, x});
                if (x == n || (tiles[y][x + 1] != 1 && tiles[y][x + 1] != 4 && tiles[y][x + 1] != 5)) return 0;
                if (y == 0 || (tiles[y - 1][x] != 2 && tiles[y - 1][x] != 3 && tiles[y - 1][x] != 4)) return 0;
            } else if (tiles[y][x] == 3) {
                to_check.push(pair<ll, ll>{y + 1, x});
                to_check.push(pair<ll, ll>{y, x + 1});
                if (y == n || (tiles[y + 1][x] != 2 && tiles[y + 1][x] != 5 && tiles[y + 1][x] != 6)) return 0;
                if (x == n || (tiles[y][x + 1] != 1 && tiles[y][x + 1] != 4 && tiles[y][x + 1] != 5)) return 0;
            } else if (tiles[y][x] == 4) {
                to_check.push(pair<ll, ll>{y + 1, x});
                to_check.push(pair<ll, ll>{y, x - 1});
                if (y == n || (tiles[y + 1][x] != 2 && tiles[y + 1][x] != 5 && tiles[y + 1][x] != 6)) return 0;
                if (x == 0 || (tiles[y][x - 1] != 1 && tiles[y][x - 1] != 3 && tiles[y][x - 1] != 6)) return 0;
            }
            if (globally_checked[y][x] == 0) globally_checked[y][x] = 2;
            if (globally_checked[y][x] == 1) globally_checked[y][x] = 3;
        }
        to_check.pop();
    }
    // cout << is_player1 << ": +" << score << " " << y << " " << x << ln;
    return score;
}


void part_a() {
    int n;
    cin >> n;
    vector<vector<ll>> tiles(n);
    for (int i = 0; i < n; i++) {
        for (int x = 0; x < n; x++) {
            char input;
            cin >> input;
            tiles[i].push_back(input - '0');
            // cout << input << " ";
        }
        // cout << ln;
    }

    // a 2d grid. 0 = unchecked, 1 = p1 checked, 2 = p2 checked, 3 = both checked.
    vector<vector<ll>> already_checked(n, vector<ll>(n, 0));

    ll p1_points = 0, p2_points = 0;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            if (already_checked[y][x] == 0 || already_checked[y][x] == 2) {
                p1_points += is_valid(tiles, already_checked, y, x, true);
            }
            if (already_checked[y][x] == 0 || already_checked[y][x] == 1) {
                p2_points += is_valid(tiles, already_checked, y, x, false);
            }
        }
    }

    cout << p1_points << " " << p2_points << ln;
}  // Took me 70 mins to write. have 1h 20m left.
// I did the brute force way of writing it - Wrote every combination for tiles. Tedious, but effective.Passes all test cases.

/*

Very easy algorithm. Iterate through every single sqaure. Run a BFS starting at that sqaure to check for adjacent connected ones.
If there are some adjacent and connected, keep exploring through those as well. Repeat until the entire loop has been exhausted without
and disconnects, and mark each tile as globally checked to avoid double counting. If there *are* disconnects, then return nothing.
If the square has already been checked, just don't run BFS. If you've exhausted the entire loop, then that means it's valid. At that
point just return the loop size as it is valid. Else do nothing. Do this for every sqaure and it'll be done.

Easy.

For the part starting from line 34: I could've implemented a less DRY way of doign it where I could reuse code, or even just write
it in a more efficient manner, through perhaps a mapping instead of THAT. However what I did works, so I'll count this a W.

*/

int main() {
    freopen("inputs/q2.txt", "r", stdin);
    part_a();
    // part_b();
}