#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct hash_tuple {
    template <class T1, class T2, class T3>

    size_t operator()(
        const tuple<T1, T2, T3>& x)
        const {
        return get<0>(x) ^ get<1>(x) ^ get<2>(x);
    }
};

ll total_permutations(char last_char, ll repeat_count, ll remaining_length, ll available_letters, ll allowed_adjacency, unordered_map<tuple<ll, ll, ll>, ll, hash_tuple>& memo) {
    if (repeat_count > allowed_adjacency) {
        return 0;
    }

    if (remaining_length == 0) {
        return 1;
    }

    if (memo.count(tie(last_char, repeat_count, remaining_length)))
        return memo.at(tie(last_char, repeat_count, remaining_length));

    ll total{};
    for (int i = 0; i < available_letters; i++) {
        if ((char(i + 'A') == last_char)) {
            total += total_permutations(i + 'A', repeat_count + 1, remaining_length - 1, available_letters, allowed_adjacency, memo);
        } else {
            total += total_permutations(i + 'A', 1, remaining_length - 1, available_letters, allowed_adjacency, memo);
        }
    }
    memo.emplace(tie(last_char, repeat_count, remaining_length), total);
    return total;
}

void part_a() {
    ll available_letters{2};
    ll allowed_adjacency{2};
    ll string_length{4};
    ll desired_index{7};

    cin >> available_letters >> allowed_adjacency >> string_length >> desired_index;

    unordered_map<tuple<ll, ll, ll>, ll, hash_tuple> memo;

    // cout << total_permutations('A', 0, string_length, available_letters, allowed_adjacency, memo) << endl;

    string prefix{};
    ll repeat_count{0};
    ll temp{0};
    ll index{0};

    for (ll index = 0; index < string_length; index++) {
        // cout << "Remaining Length: " << string_length - index << endl;
        for (int letter = 0; letter < available_letters; letter++) {
            if ((prefix.size() != 0) && (prefix.back() == char(letter + 'A'))) {
                temp += total_permutations(char(letter + 'A'), repeat_count + 1, string_length - index - 1, available_letters, allowed_adjacency, memo);
            } else {
                temp += total_permutations(char(letter + 'A'), 1, string_length - index - 1, available_letters, allowed_adjacency, memo);
            }

            if (temp >= desired_index) {
                // cout << prefix.back() << char(letter + 'A') << endl;
                if ((prefix.size() == 0) || (prefix.back() == char(letter + 'A')))
                    repeat_count++;
                else
                    repeat_count = 1;
                temp -= total_permutations(char(letter + 'A'), repeat_count, string_length - index - 1, available_letters, allowed_adjacency, memo);
                prefix += char(letter + 'A');
                // cout << "New String: " << prefix << endl;
                break;
            }
        }
    }

    cout << prefix << endl;
    cout << endl;
}  // Passes all the test cases so gets all 24/24 points. Lovely. This took me way too long to write.
/* Implementation is interesting. n is too big to brute force through all permutations at O(n), but through dynamic programming we
can do it in linear time, but based on the string length instead, which is max 12. We use dynamic programming to find exactly how many
combinations there are that start with each possible prefix and construct a memo table. With this information, we can use a greedy
algorithm to build each character by selecting through them until the new prefix is >= to the index, then narrowing down. A lot like
a binary search, but not binary and with extreme pre-calculation. Just DP + greedy. In some ways not too bad, in other ways, very hard */

int main() {
    freopen("input.txt", "r", stdin);
    part_a();
    // part_b();
}