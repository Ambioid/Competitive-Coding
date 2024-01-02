#include <bits/stdc++.h>

using namespace std;
#define ln '\n'
typedef long long ll;

set<vector<ll>> combos(ll str_len) {
    if (str_len == 1) return {{1}};

    set<vector<ll>> temp = combos(str_len - 1);

    set<vector<ll>> output{};
    for (auto iter : temp) {
        iter.push_back(1);
        output.insert(iter);
        iter.erase(iter.end() - 1);
        iter.back()++;
        output.insert(iter);
    }

    return output;
}

ll check(const string& str, vector<ll> input) {
    ll sum = 0;
    vector<string> checker{};
    for (const auto& iter : input) {
        checker.push_back(str.substr(sum, iter));
        sum += iter;
        cout << checker.back() << " ";
    }
    cout << ln;
    vector<string> reverse_checker = checker;
    reverse(reverse_checker.begin(), reverse_checker.end());
    return (checker == reverse_checker);
}


void part_a() {
    string input;
    cin >> input;

    // for (int i = 0; i < input.size() / 2; i++) {
    //     if (input.substr(0, i) == input.substr(input.size() - i)) {
    //         cout << input.substr(0, i) << " " << input.substr(input.size() - i) << ln;
    //         // cout << "A" << endl;
    //     }
    // }

    auto temp = combos(input.size() / 2);
    // temp.erase(prev(temp.end()));
    for (const auto& iter : temp) {
        for (const auto& iter2 : iter) {
            cout << iter2 << " ";
        }
        cout << ln;
    }

    // set<vector<ll>> temp2{};
    ll correct{};

    for (const auto& iter1 : temp) {
        vector<ll> temptemp{iter1};

        // for (const auto& iter2 : temptemp) {
        //     cout << iter2 << " ";
        // }
        // cout << ln;
        if (temptemp.back() == input.size() / 2) {
            temptemp.push_back(1);
            temptemp.emplace_back(temptemp[0]);
        } else {
            for (int i = 0; i < iter1.size(); i++) {
                // cout << iter1[i] << " ";
                if (i == 0) {
                    temptemp.back() *= 2;
                    if (input.size() % 2 == 1) {
                        temptemp.back()++;
                    }

                } else {
                    temptemp.push_back(iter1[iter1.size() - i - 1]);
                }
            }
        }
        correct += check(input, temptemp);

        for (int i = 0; i < iter1.size(); i++) {
            // cout << iter1[i] << " ";
            temptemp.push_back(iter1[iter1.size() - i - 1]);
        }
        correct += check(input, temptemp);
        // cout << ln;
        // temp2.insert(temptemp);
        for (const auto& iter2 : temptemp) {
            cout << iter2 << " ";
        }
        cout << ln << ln;
    }

    cout << correct << ln;
}  // Took me 85 minutes to do.
// Fails XX
int main() {
    freopen("inputs/q1.txt", "r", stdin);
    // while (true)
    part_a();
    // part_b();
}