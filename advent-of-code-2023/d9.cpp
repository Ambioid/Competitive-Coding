#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

typedef long long ll;

void part_a() {
    // The line length is static and it'd be really annoying to develop a method to figure out line length so I figure it out myself
    int line_length{21};
    ll sum{0};
    ll input{};

    while (cin >> input) {
        vector<vector<ll>> values{{input}};
        for (int i = 0; i < line_length - 1; i++) {
            cin >> input;
            values.at(0).push_back(input);
        }

        bool not_zero{true};
        while (not_zero) {
            not_zero = false;
            values.push_back({});
            for (int i = 0; i < values.at(values.size() - 2).size() - 1; i++) {
                values.at(values.size() - 1).push_back(values.at(values.size() - 2).at(i + 1) - values.at(values.size() - 2).at(i));
                if (*values.at(values.size() - 1).rbegin() != 0) {  // If it has anything
                    not_zero = true;
                }
            }
        }

        for (int i = values.size() - 2; i >= 0; i--) {
            values.at(i).push_back(*values.at(i).rbegin() + *values.at(i + 1).rbegin());
        }
        for (const auto& iter : values) {
            for (const auto& iter2 : iter) {
                cout << iter2 << " ";
            }
            cout << endl;
        }

        sum += *values.at(0).rbegin();
        cout << endl;
    }
    cout << "Final Sum: " << sum << endl;
}

void part_b() {
    // The code for part B is basically the same thing, but swap the plus for minus.
    int line_length{21};
    ll sum{0};
    ll input{};

    while (cin >> input) {
        vector<vector<ll>> values{{input}};
        for (int i = 0; i < line_length - 1; i++) {
            cin >> input;
            values.at(0).push_back(input);
        }

        bool not_zero{true};
        while (not_zero) {
            not_zero = false;
            values.push_back({});
            // Find the rate of change until it reaches 0
            for (int i = 0; i < values.at(values.size() - 2).size() - 1; i++) {
                values.at(values.size() - 1).push_back(values.at(values.size() - 2).at(i + 1) - values.at(values.size() - 2).at(i));
                if (*values.at(values.size() - 1).rbegin() != 0) {  // check if it has zero
                    not_zero = true;
                }
            }
        }
        // Iterate through all backwards, excluding the last vector(it's 0)
        for (int i = values.size() - 2; i >= 0; i--) {
            values.at(i).insert(values.at(i).begin(), *values.at(i).begin() - *values.at(i + 1).begin());
        }

        // Print for debugging
        for (const auto& iter : values) {
            for (const auto& iter2 : iter) {
                cout << iter2 << " ";
            }
            cout << endl;
        }

        sum += *values.at(0).begin();
        cout << endl;
    }
    cout << "Final Sum: " << sum << endl;
}

int main() {
    freopen("inputs/d9.txt", "r", stdin);
    // part_a();
    part_b();
}