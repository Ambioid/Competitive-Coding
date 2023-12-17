#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    while (true) {
        string arragement{"abcd"};
        long long list_spot{24};

        cin >> arragement >> list_spot;

        string output{};

        vector<vector<long long>> possible_spots(arragement.size());

        vector<char> temp(arragement.size(), '_');

        for (long long i{0}; i < arragement.size(); i++) {
            long long pos{arragement.find('a' + i)};
            temp.at(pos) = 'a' + i;

            long long count{1};
            while (((pos - count) >= 0) && (temp.at(pos - count) != '_')) {
                temp.at(pos - count) = 'a' + i;
                count += 1;
            }

            for (long long iter{0}; iter < arragement.size(); iter++) {
                // cout << "B:" << temp.at(iter) << ":A";
                if (temp.at(iter) == ('a' + i)) {
                    possible_spots.at(i).push_back(iter);
                }
            }
        }

        long reoccurs{1};
        for (long long i{0}; i < possible_spots.size(); i++) {
            reoccurs *= possible_spots.at(i).size();
        }

        for (long long car{0}; car < possible_spots.size(); car++) {
            long long max_size = possible_spots.at(car).size();
            // cout << max_size << " " << reoccurs;
            // long long t_list_spot{list_spot % max_size}

            cout << char('A' + possible_spots.at(car).at(((list_spot - 1) / (reoccurs / max_size)) % max_size));
            reoccurs /= max_size;
        }

        cout << "\n";
    }
}

// Passes every test case basically instantly. 25/25 points. The last 2 caught me, but switching to longs fixed the issue. ALWAYS CHECK THE INPUT RANGE!!
// Solving the actual problem took me like 45m (but should have been faster really), but figuring out how to efficiently output the ith permutation
// took me like an hour to figure out. waaay too long. Seriously what even was that lmao


