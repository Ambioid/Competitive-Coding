#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    // freopen("input.txt", "r", stdin);

    ll total_coins, sum;
    cin >> total_coins >> sum;
    vector<ll> coins(total_coins);
    for (ll i = 0; i < total_coins; i++) {
        ll temp;
        cin >> temp;
        coins.at(i) = temp;
    }
    vector<ll> memo(sum + 1);

    memo.at(0) = 1;

    for (ll i = 0; i < sum + 1; i++) {
        for (const auto& coin : coins) {
            if (coin <= i) {
                memo.at(i) += memo.at(i - coin) % 1000000007;
            }
        }
    }
    cout << (memo.back() % ll(1000000007)) << endl;
}