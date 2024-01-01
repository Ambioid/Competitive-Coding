#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    // freopen("input.txt", "r", stdin);

    int target{27};
    cin >> target;

    vector<int> dp(target + 1, 0);

    for (int i = 1; i < target + 1; i++) {
        int temp{INT_MAX};
        for (char digit : to_string(i)) {
            if (digit != '0') temp = min(temp, dp[i - digit + '0']);
        }
        dp[i] = temp + 1;
    }
    cout << dp[target] << endl;
}

/*
This one is actually really simple. It's basically the same as Coin-Combinations-I, except the 'coin' values change. Just have a 1d vector starting from 0, and
for each index, just iterate through al the digits and check which value is the has lowest index when subtracting the digit from index, and set that to new index.
This just changes every iteration until you finally reach the final point. Pretty simple.

- Did not take into account 0 digit makes number point to itself, just added an if statement for that condition.

*/