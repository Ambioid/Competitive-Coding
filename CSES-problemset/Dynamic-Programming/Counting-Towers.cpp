#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    const ll mod = 1e9 + 7;

    vector<vector<ll>> tower(1e6, vector<ll>(2));
    tower[0][0] = 1;
    tower[0][1] = 1;

    for (ll y = 1; y < 1e6; y++) {
        tower[y][0] = ((tower[y - 1][0] % mod) * 4 % mod + (tower[y - 1][1] % mod) * 1) % mod;
        tower[y][1] = ((tower[y - 1][0] % mod) * 1 + (tower[y - 1][1] % mod) * 2 % mod) % mod;
        // cout << (tower[y][0] + tower[y][1]) % mod << endl;
    }


    ll cases{};
    cin >> cases;

    for (ll current_case = 0; current_case < cases; current_case++) {
        ll n = 1337;
        cin >> n;


        cout << (tower[n - 1][0] + tower[n - 1][1]) % mod << endl;
    }
}

/*
This is one I could write a logically correct solution for without reading the solution so I'm proud of that. Also when you get an easy question it's quite nice??
because it reminds you how this whole DP thing works, it reminds you how this whole thing functions, as well as giving you a different easier case to think about
when writing solutions to different problems. Super nice. Also reading example code taught me about the #IFDEF LOCAL thing which is has been super helpful to me
for my other competitions. Epic.

Mistakes:
- When doing the 2d DP table I messed up with the x and y axis a lot
- wtf is going on with this modulus stuff man????
- Got TLE'd
*/