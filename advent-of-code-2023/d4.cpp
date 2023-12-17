#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

void part_a() {
    string input{};
    long card_points{0};
    long sum{0};
    set<int> winning_numbers{};
    set<int> held_numbers{};

    bool card_or_matrix{0};  // 0 == card, 1 == matrix
    while (cin >> input) {
        // cout << input << " ";
        // cout << input.at(0) << endl;
        if (input == "Card") {
            for (const auto &iter : held_numbers) {
                std::cout << iter << " ";
            }
            std::cout
                << endl;
            for (const auto &iter : winning_numbers) {
                std::cout << iter << " ";
                if (held_numbers.count(iter)) {
                    // cout << " Match!!";
                    if (card_points == 0) {
                        card_points = 1;
                    } else {
                        card_points *= 2;
                    }
                }
                // cout << endl;
            }
            std::cout << endl;
            std::cout << "Card points:" << card_points << endl
                      << endl;
            sum += card_points;

            winning_numbers = {};
            held_numbers = {};
            card_points = 0;
            card_or_matrix = 2;
        }
        // cout << input.at(0) << endl;
        if ((input.size() > 1) && (input.back() == ':')) {
            card_or_matrix = 0;
        } else if ((card_or_matrix == 0) && (isdigit(input.at(0)))) {
            int temp{0};
            for (const auto &iter : input) {
                temp *= 10;
                temp += iter - '0';
            }
            winning_numbers.insert(temp);

        } else if (input.at(0) == '|') {
            card_or_matrix = 1;
        } else if ((card_or_matrix == 1) && (isdigit(input.at(0)))) {
            int temp{0};
            for (const auto &iter : input) {
                temp *= 10;
                temp += iter - '0';
            }
            held_numbers.insert(temp);
        }
    }

    std::cout << "End Sum: " << sum << endl;
}

void part_b() {
    string input{};
    long subsequent_duplicates{0};
    set<int> winning_numbers{};
    set<int> held_numbers{};
    map<int, int> duplicate_map{};
    int card_number{0};
    bool card_or_matrix{0};  // 0 == card, 1 == matrix
    while (cin >> input) {
        if (input == "Card") {
            // for (const auto &iter : held_numbers) {
            //     cout << iter << " ";
            // }
            for (const auto &iter : winning_numbers) {
                std::cout << iter << " ";
                if (held_numbers.count(iter)) {
                    // cout << " Match!!";
                    subsequent_duplicates += 1;
                }
                // cout << endl;
            }

            for (int i{card_number + 2}; i < subsequent_duplicates + card_number + 1; i++) {
                std::cout << endl
                          << card_number << ", " << subsequent_duplicates << endl;
                std::cout << i << ", " << subsequent_duplicates + card_number + 1 << endl;
                // cout << "ASDWTKUFGHWOSDFLIUGHWRUIOSTGH";
                if (duplicate_map.count(i)) {
                    duplicate_map.at(i) += duplicate_map[card_number];
                    // cout << "A";
                } else {
                    // cout << "b";
                    duplicate_map.insert(pair{i, duplicate_map[card_number]});
                }
            }

            winning_numbers = {};
            held_numbers = {};
            subsequent_duplicates = 0;
            card_or_matrix = 2;
        }
        // cout << input.at(0) << endl;

        if ((input.size() > 1) && (input.back() == ':')) {
            card_or_matrix = 0;
            card_number += 1;
            if (duplicate_map.count(card_number) == 0) {
                duplicate_map.insert({card_number, 1});
            }

        } else if ((card_or_matrix == 0) && (isdigit(input.at(0)))) {
            int temp{0};
            for (const auto &iter : input) {
                temp *= 10;
                temp += iter - '0';
            }
            winning_numbers.insert(temp);

        } else if (input.at(0) == '|') {
            card_or_matrix = 1;
        } else if ((card_or_matrix == 1) && (isdigit(input.at(0)))) {
            int temp{0};
            for (const auto &iter : input) {
                temp *= 10;
                temp += iter - '0';
            }
            held_numbers.insert(temp);
        }
    }
    int card_sum{0};
    cout << endl;
    for (const auto &iter : duplicate_map) {
        card_sum += iter.second;
        cout << iter.first << ", " << iter.second << endl;
    }
    std::cout << "End Sum: " << card_sum << endl;
}

int main() {
    freopen("inputs/d4.txt", "r", stdin);

    // part_a();
    part_b();
}
