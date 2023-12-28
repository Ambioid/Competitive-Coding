#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void part_a() {  // This took me 20m to do, it really should not have.
    string base_row{};
    cin >> base_row;
    string new_row{base_row};

    vector<char> letters{'R', 'G', 'B'};

    // cout << new_row.substr(i, 2) << endl;
    // ll row = 0;
    for (int y = 1; y < base_row.size(); y++) {
        for (int i = 0; i < new_row.size() - 1; i++) {
            string sub = new_row.substr(i, 2);
            bool dont_skip = true;
            for (const auto letter : letters) {
                if (count(sub.begin(), sub.end(), letter) == 2) {
                    new_row.at(i) = letter;
                    dont_skip = false;
                    break;
                }
                if (dont_skip) {
                    for (const auto letter : letters) {
                        if (count(sub.begin(), sub.end(), letter) == 0) {
                            new_row.at(i) = letter;
                            break;
                        }
                    }
                }
            }
        }
        new_row.pop_back();
        // cout << new_row << endl;
    }
    cout
        << new_row.at(0) << endl
        << endl;
}  // This part A gets all 23 marks. Not much else to say.

bool is_valid(string original_permutation) {
    vector<char> letters{'R', 'G', 'B'};
    string new_row = original_permutation;
    // cout << new_row << endl;
    for (int i = 0; i < new_row.size(); i++) {
        string sub = new_row.substr(i, 2);
        bool dont_skip = true;
        for (const auto letter : letters) {
            if (count(sub.begin(), sub.end(), letter) == 2) {
                new_row.at(i) = letter;
                dont_skip = false;
                break;
            }
            if (dont_skip) {
                for (const auto letter : letters) {
                    if (count(sub.begin(), sub.end(), letter) == 0) {
                        new_row.at(i) = letter;
                        break;
                    }
                }
            }
        }
    }
    new_row.pop_back();
    if (new_row == "RRGBRGBB") {
        cout << original_permutation << endl;
    }
    return new_row == "RRGBRGBB";
}
void part_b() {  // This LITERALLY took me 10 minutes :(. not very efficient either...
    vector<char> letters{'R', 'G', 'B'};
    ll total{};
    for (int c1 = 0; c1 < 3; c1++) {
        for (int c2 = 0; c2 < 3; c2++) {
            for (int c3 = 0; c3 < 3; c3++) {
                for (int c4 = 0; c4 < 3; c4++) {
                    for (int c5 = 0; c5 < 3; c5++) {
                        for (int c6 = 0; c6 < 3; c6++) {
                            for (int c7 = 0; c7 < 3; c7++) {
                                for (int c8 = 0; c8 < 3; c8++) {
                                    for (int c9 = 0; c9 < 3; c9++) {
                                        string input{""};
                                        input += letters[c1];
                                        input += letters[c2];
                                        input += letters[c3];
                                        input += letters[c4];
                                        input += letters[c5];
                                        input += letters[c6];
                                        input += letters[c7];
                                        input += letters[c8];
                                        input += letters[c9];
                                        // cout << input << endl;
                                        total += is_valid(input);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout << total << endl;
}  // ...Got all 3 marks for this one though. Worth it....?

// Didn't get any marks for part C and D though.

int main() {
    // freopen("inputs/q1.txt", "r", stdin);
    // while (true)
    //     part_a();
    part_b();
}
