#include <bits/stdc++.h>
#define ln '\n'
using namespace std;

typedef long long ll;

/** Computes nCk mod p using dynamic programming */
int binomial(int n, int k) {
    // dp[i][j] stores iCj
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    // base cases described above
    for (int i = 0; i <= n; i++) {
        /** i choose 0 is always 1 since there is exactly one way*/
        dp[i][0] = 1;
        /* i choose i is always 1 since there is exactly one way*/
        if (i <= k) dp[i][i] = 1;
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 1; j <= min(i, k); j++) {
            if (i != j) {  // skips over the base cases
                // uses the recurrence relation above
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]);
            }
        }
    }
    return dp[n][k];  // returns nCk modulo p
}

ll find_permutations(map<pair<ll, char>, ll>& memo, const string& digits, const ll& remaining_digits, const char& largest_used_digit) {
    if (remaining_digits == 0) return 1;

    if (memo.count(pair<int, char>{remaining_digits, largest_used_digit})) return memo.at(pair<int, char>{remaining_digits, largest_used_digit});

    ll permutations = 0;
    for (const auto& iter : digits) {
        if (find(digits.begin(), digits.end(), iter) - digits.begin() > find(digits.begin(), digits.end(), largest_used_digit) - digits.begin())
            permutations += find_permutations(memo, digits, remaining_digits - 1, iter);
    }

    memo.emplace(pair<int, char>{remaining_digits, largest_used_digit}, permutations);

    return permutations;
}

void part_a() {
    int n;
    cin >> n;


    string digits = " ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

    map<pair<ll, char>, ll> memo{};

    int password_length = 0;

    ll x = binomial(36, password_length);

    while (x <= n) {
        password_length++;
        x += binomial(36, password_length);
    }
    // while (find_permutations(memo, digits, password_length, ' ') <= n) password_length++;
    ll current_length = 0;
    string output_string{};
    char last_digit = ' ';

    int temp_length = 0;
    bool increase_size = true;
    bool unfinished = true;

    while (output_string.size() < password_length) {
        for (int i = find(digits.begin(), digits.end(), last_digit) - digits.begin() + 1; i < digits.size(); i++) {  // Iterate through every possible char
            char digit = digits[i];

            current_length += find_permutations(memo, digits, temp_length, digit);
            // cout << digit << ": " << current_length << ln;

            if (current_length >= n) {
                current_length -= find_permutations(memo, digits, temp_length, digit);
                last_digit = digit;
                output_string += digit;
                temp_length--;


                increase_size = false;
                break;
            }
        }

        if (increase_size && output_string.size()) unfinished = false;
        if (increase_size) temp_length++;  // The increase size only happens one way

        increase_size = true;
        // cout << "New loop:" << ln << output_string << ln;
    }
    cout << output_string << ln;
}

/* Program has 2 phases:

1. Iterate through every char and add up the amount of permutations you can get with it. if you've gone through
all the chars and still haven't reached it, then add 1 more digit to check with, and then repeat until you do.

2. When you do find a digit whose permutations (plus prev permutations) exceed or equal the desired index, then you
know that you are correct. In such case, add that letter to the output string, decrease the digits searching by 1,
backtrack, and then keep going from there.


Note: This probably can be done entirely with the choose function. I may come back to re-write
this again but better. TBH I could go back and re-write most my solution better.


*/
void part_c() {
    map<pair<ll, char>, ll> memo{};
    string digits = " ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    int i = 0;
    while (find_permutations(memo, digits, i, ' ') > 0) {
        i++;

        cout << find_permutations(memo, digits, i, ' ') << ln;
    }  // ans is 9075135300;
}

int main() {
    // freopen("inputs/q3.txt", "r", stdin);
    while (true) part_a();
    // part_b();
    // part_c();
}