#include <algorithm>
#include <cstdio>
#include <deque>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    while (true) {
        string endpoints{"acdb"};

        cin >> endpoints;

        long total{0};
        // deque<string> queue{""};
        deque<int> max_end{-1};
        deque<int> max_start{-1};
        deque<int> wolf_count{0};

        unordered_set<string> checked_positions{};
        int max_wolves{0};

        while (max_end.empty() == false) {
            int current_start{max_start.front() + 1};
            // cout << "Current start: " << current_start << endl;

            if ((current_start == endpoints.size())) {
                if ((wolf_count.front() > 0)) {

                    total += 1;
                    max_wolves = max(max_wolves, wolf_count.front());
                }

                max_start.pop_front();
                max_end.pop_front();
                wolf_count.pop_front();

            } else {

                if ((endpoints.at(current_start) - 'a') > max_end.front()) {
                    max_start.push_back(current_start);
                    max_end.push_back(endpoints.at(current_start) - 'a');
                    wolf_count.push_back(wolf_count.front() + 1);
                }

                max_start.push_back(current_start);
                max_end.push_back(max_end.front());
                wolf_count.push_back(wolf_count.front());

                max_start.pop_front();
                max_end.pop_front();
                wolf_count.pop_front();
            }
        }

        cout << total << " " << max_wolves << endl;
    }
}
// "Oh yeah, I've done something like this before." (Prev BIO Q3, the strings one. Very similar question)
