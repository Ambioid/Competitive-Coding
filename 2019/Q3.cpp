#include <algorithm>
#include <cstdio>
#include <deque>
#include <iostream>
#include <iterator>
#include <set>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
    while (true) {
        int required_size{0};
        string front_pattern{};

        cin >> required_size >> front_pattern;

        string new_string{front_pattern};
        deque<set<char>> strings = {{}};
        deque<set<char>> not_in_strings = {{}};

        for (int i{0}; i < required_size; i++) {
            not_in_strings.front().insert(i + 'A');
        }
        for (const auto& iter : front_pattern) {
            strings.front().insert(iter);
            not_in_strings.front().erase(iter);
        }

        int finished_count{0};

        while (strings.empty() != true) {
            // Iterate through all the letters that haven't been used yet.
            if (not_in_strings.front().empty()) {
                // cout << "Another finished. \n";
                finished_count += 1;
            } else {
                for (const auto& letter : not_in_strings.front()) {
                    // cout << letter << endl;
                    // cout  << "Front and end: \n"<< *strings.front().begin() << ", " << *not_in_strings.front().rbegin() <<"\n";

                    // if letter is smaller than smallest currently, or larger than the largest currently.
                    if ((letter < *strings.front().begin()) || (letter > *not_in_strings.front().rbegin())) {
                        strings.push_back(strings.front());
                        strings.back().insert(letter);
                        not_in_strings.push_back(not_in_strings.front());
                        not_in_strings.back().erase(letter);
                    }
                }

                // cout << "\nLoop:";
                // for (const auto& iter1: strings){
                //     cout << "\nString: \n";
                //     for (const auto& iter2 : iter1){
                //         cout << iter2 << " ";
                //     }
                // }
                // cout << "\nEnd of loop. \n";
            }
            // std::cout << strings.front() << endl;
            for (const auto& iter : strings.front()) {
                cout << iter << " ";
            }
            cout << endl;
            strings.pop_front();
            not_in_strings.pop_front();
        }

        cout << finished_count << endl;
    }
}

// Fails:  14 N, 18 QPON, and 18 R.
// 18/24. Not a failure, but can be much better.
// Completed mostly within about 1h 30m?
// Approach is just a BFS of possible string setups. Not very efficient. Too much string copying.
// Also just incorrect occasionally. Will have to revisit.
