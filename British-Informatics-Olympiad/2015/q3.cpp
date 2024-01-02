#include <bits/stdc++.h>
#define ln '\n'
using namespace std;

typedef long long ll;

ll find_permutations(map<map<char, ll>, ll>& memo, map<char, ll> unused_chars) {
    if (memo.count(unused_chars)) return memo.at(unused_chars);

    ll sum{};
    for (const auto& iter : unused_chars) sum += iter.second;

    if (sum == 1) {
        // cout << "Final triggered: " << sum << ln;
        return sum;
    }

    ll permutations{};

    for (const auto& iter : unused_chars) {
        if (unused_chars.at(iter.first) == 0) continue;
        map<char, ll> temp{unused_chars};
        temp.at(iter.first)--;

        // cout << iter.first << temp.at(iter.first) << ' ';
        // for (const auto& iter2 : temp) cout << iter2.first << iter2.second << " ";
        // cout << ln;
        permutations += find_permutations(memo, temp);
    }
    memo.emplace(unused_chars, permutations);

    // cout << ln;
    // cout << "Perms: " << permutations << ln;
    return permutations;
}

void part_a() {
    ll a, b, c, d, desired_index;
    cin >> a >> b >> c >> d >> desired_index;
    map<map<char, ll>, ll> memo;
    // desired_index--;
    map<char, ll> to_use{{'A', a}, {'B', b}, {'C', c}, {'D', d}};
    ll permuations = find_permutations(memo, to_use);

    ll remaining_length{};
    for (const auto& iter : to_use) remaining_length += iter.second;
    ll current_index{0};
    string final_string{""};


    while (remaining_length) {
        ll sum = 0;
        for (const auto& iter : to_use) sum += iter.second;
        for (const auto& iter : to_use) {
            // cout << "Next: " << iter.first << ln;
            if (to_use.at(iter.first) == 0) {
                // cout << "Skipping: " << iter.first << ln;
                continue;
            }
            // Not sure why it doesn't output the last letter, so quick hack.
            if (sum == 1) {
                final_string += iter.first;
                break;
            }

            map<char, ll> temp = to_use;
            temp.at(iter.first)--;
            current_index += find_permutations(memo, temp);
            // cout << ln << iter.first;
            // cout << ln << current_index << " ";
            // for (const auto& iter2 : to_use) cout << iter2.first << iter2.second << " ";

            if (current_index >= desired_index) {
                // cout << " Yes ";
                final_string += (iter.first);
                to_use = temp;
                // cout << final_string;
                // cout << current_index << endl;
                current_index -= find_permutations(memo, temp);
                // cout << ;
                break;  // BRUH I can't believe I spent 30 minutes debugging because I wrote continue here
            }
            // cout << final_string << iter.first << current_index;
        }

        remaining_length--;
        // cout << endl;
    }

    cout << ln << final_string << ln;
}
/*
Bro this is literally the same as the 2020 question 3. Proud of myself for spotting that really easily though.

Refer to that answer. Use recursive DP function to create a mapping between how many permutations there are
per set of unused characters. Based on this, construct a string by repeatedly interating until the amount of
permutations matches the desired index.  bruh at the end I was so close but was dying to edge cases. I spent
so much time trying to figure out why it didn't restart at A, and didn't realize I shoould've used a break
instead of a continue. So many edge cases. For some reason this wouldn't output JUST the last letter? Not sure
why that is. I should come back and re-write this at some point.

Anyways, this solution worked first try. 25/25 points. Nice.

*/

int main() {
    freopen("inputs/q3.txt", "r", stdin);
    // while (true)
    part_a();
    // part_b();
}