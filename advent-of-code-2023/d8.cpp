#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

typedef long long ll;

void part_a() {
    string location{"AAA"};
    map<string, vector<string>> adjacency_map{};

    string instructions{};
    cin >> instructions;

    string input{};
    string location_to_input_at{};
    while (cin >> input) {
        if (input.at(0) == '(') {
            adjacency_map.at(location_to_input_at).push_back(input.substr(1, 3));
        } else if (*input.rbegin() == ')') {
            adjacency_map.at(location_to_input_at).push_back(input.substr(0, 3));
        } else if (input != "=") {
            location_to_input_at = input;
            adjacency_map.insert({input, {}});
        }
    }

    for (const auto& iter : adjacency_map) {
        cout << iter.first << " " << iter.second.at(0) << " " << iter.second.at(1) << endl;
    }

    ll i{0};
    while (location != "ZZZ") {
        if (instructions.at(i % instructions.size()) == 'L') {
            location = adjacency_map.at(location).at(0);
        } else if (instructions.at(i % instructions.size()) == 'R') {
            location = adjacency_map.at(location).at(1);
        }

        i++;
    }
    cout << "Steps: " << i << endl;
}

void part_b() {
    map<string, vector<string>> adjacency_map{};

    string instructions{};
    cin >> instructions;

    string input{};
    string location_to_input_at{};
    while (cin >> input) {
        if (input.at(0) == '(') {
            adjacency_map.at(location_to_input_at).push_back(input.substr(1, 3));
        } else if (*input.rbegin() == ')') {
            adjacency_map.at(location_to_input_at).push_back(input.substr(0, 3));
        } else if (input != "=") {
            location_to_input_at = input;
            adjacency_map.insert({input, {}});
        }
    }

    for (const auto& iter : adjacency_map) {
        cout << iter.first << " " << iter.second.at(0) << " " << iter.second.at(1) << endl;
    }
    cout << endl;
    vector<string> location_list{};
    for (const auto& iter : adjacency_map) {
        if (iter.first.at(2) == 'A') {
            location_list.push_back(iter.first);
            cout << iter.first << " ";
        }
    }

    cout << "\nStarting:\n\n";
    vector<ll> time_list{};
    bool not_complete{true};

    cout << "Number of ghosts: " << location_list.size() << endl;
    not_complete = false;
    for (string& location : location_list) {
        ll i{0};
        while (location.at(2) != 'Z') {
            if (instructions.at(i % instructions.size()) == 'L') {
                location = adjacency_map.at(location).at(0);
            } else if (instructions.at(i % instructions.size()) == 'R') {
                location = adjacency_map.at(location).at(1);
            }

            i++;
            cout << location << endl;
        }
        cout << "Ghost completed. " << i << endl;
        time_list.push_back(i);
    }
    ll total_steps{1};

    for (int i = 0; i < time_list.size(); i++) {
        cout << total_steps << time_list.at(i) << endl;
        total_steps = lcm(total_steps, time_list.at(i));
    }
    cout << "Steps: " << total_steps << endl;

    // This one takes a long time..... it worked on my test input so I am honestly just trusting that this really long runtime is supposed to be. I tried its current number and it said it was too low so I figure out im on the right track
}

int main() {
    freopen("inputs/d8.txt", "r", stdin);
    // part_a();
    part_b();
}