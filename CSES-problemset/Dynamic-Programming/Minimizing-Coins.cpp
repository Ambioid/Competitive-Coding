#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll coins_total, sum;
    cin >> coins_total >> sum;

    ll temp;
    vector<ll> coins{};
    for (ll i = 0; i < coins_total; i++) {
        cin >> temp;
        coins.push_back(temp);
    }
}