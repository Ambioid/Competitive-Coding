#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    ll a, b;
    cin >> a >> b;

    vector<vector<ll>> grid(b, vector<ll>(a));

    for (int y = 0; y < grid.size(); y++) {
        for (int x = 0; x < grid[0].size(); x++) {
            ll temp = 0;

            if ((y > 0 || x > 0) && (y != x)) {
                temp = LONG_LONG_MAX;
                for (int temp_y = 0; temp_y < y; temp_y++) {
                    temp = min(temp, grid[temp_y][x] + grid[y - temp_y - 1][x] + 1);
                    // cout << grid[temp_y][x] + grid[y - temp_y][x] + 1;
                }
                for (int temp_x = 0; temp_x < x; temp_x++) {
                    temp = min(temp, grid[y][temp_x] + grid[y][x - temp_x - 1] + 1);
                    // cout << grid[y][temp_x] << grid[y][x - temp_x] << " ";
                    // cout << x << temp_x << " ";
                }
            }
            grid[y][x] = temp;
            // cout << " " << grid[y][x] << " ";
        }
        // cout << endl;
    }
    cout << grid.back().back() << endl;
}

/*
I'm proud of this one because I figured out how to do it all on my own, and it worked first try (if you don't count me uploading
the wrong file first time). I was reading through only problems and realizing how I solved that one actually helped me figure out
how to solve this one, and I think I am starting to get a lot of insight into dynamic programming. I think I am starting to get a
lot of understanding into how this kinda stuff works, like you literally start from nothing and just keep building outwards until
you reach the final state. I'm proud of figuring out how this one works, figuring out how you build the final state from nothing.
I hear that at some point dynamic programming just kinda clicks for you, and I hope this was in fact that moment. I think I am
really starting to get the hang of this stuff now.
Thank you notebook for being there for me to write all this in as well hehe..

Mistakes:
- Forgot to make sure to do nothing if x==0 &&y==0
- Did not realize that x and y will be one higher than the index (when calculating temp), so I should have -1'd it when I forgot to.

That's it! :D

*/