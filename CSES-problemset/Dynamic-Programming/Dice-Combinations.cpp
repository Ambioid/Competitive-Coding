#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// Simple recursive DP. Just find the combinations that you can get from any state, and calculate those recursively.
ll find_combinations(unordered_map<ll, ll> &memo, ll n) {
    if (memo.count(n)) return memo.at(n);
    if (n < 0) return 0;
    if (n == 0) return 1;

    ll combinations{0};
    for (ll i = 1; i < 7; i++) {
        combinations += (find_combinations(memo, n - i));
    }
    combinations = combinations % ll(1e9 + 7);

    memo.emplace(n, combinations);
    // cout << combinations << endl;
    return combinations;
}

int main() {
    ll n{0};
    cin >> n;

    unordered_map<ll, ll> memo{};

    cout << (find_combinations(memo, n) % ll(1e9 + 7)) << endl;
}