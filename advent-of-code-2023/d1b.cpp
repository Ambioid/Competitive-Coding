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

int main() {
    freopen("inputs/d1b.txt", "r", stdin);

    vector<string> words{"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    string current_line{};
    long long sum{0};

    while (cin >> current_line) {  // Repeats per line.
        int right_pos{-1};
        int left_pos{current_line.size()};

        int front_value{0};
        int back_value{0};

        for (int i{0}; i < current_line.size(); i++) {
            if (isdigit(current_line.at(i))) {
                if (front_value == 0) {
                    left_pos = i;
                    front_value = current_line.at(i) - '0';
                }

                back_value = current_line.at(i) - '0';
                right_pos = i;
            }
        }

        for (int i{0}; i < words.size(); i++) {
            // cout << "Word: " << words.at(i) << endl;
            int temp{current_line.find(words.at(i))};
            if (temp != std::string::npos) {
                if (temp < left_pos) {
                    // cout << "Min: " << temp << endl;
                    left_pos = temp;
                    front_value = (i) + 1;
                }
            }

            // temp has to be redeclared to find the last occurance for if it appears twice.
            temp = current_line.rfind(words.at(i));
            if (temp != std::string::npos) {
                // cout << "Temp: " << temp << endl;
                if ((temp) > right_pos) {
                    // cout << "Max: " << temp << endl;
                    right_pos = temp;
                    back_value = (i) + 1;
                }
            }

            // mini = max(mini, temp);
            // maxi = min(maxi, temp);
        }

        sum += front_value * 10 + back_value;
        // cout << front_value << " " << back_value << " ";
        // cout << current_line << " " << endl;
    }
    cout << sum << endl;
}