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
    string input{};
    vector<string> galaxy_map{};
    while (cin >> input) {
        galaxy_map.push_back(input);
        if (!count(input.begin(), input.end(), '#')) {
            galaxy_map.push_back(input);
        }
    }

    // Iterate through every column
    for (int x{galaxy_map.at(0).size() - 1}; x > 0; x--) {
        bool no_hashtag = true;
        for (int y = 0; y < galaxy_map.size(); y++) {
            if (galaxy_map.at(y).at(x) == '#') {
                no_hashtag = false;
                break;
            }
        }
        if (no_hashtag) {
            for (int y = 0; y < galaxy_map.size(); y++) {
                galaxy_map.at(y).insert(galaxy_map.at(y).begin() + x, '.');
            }
        }
    }
    map<pair<int, int>, int> star_coords{};

    int counter{1};
    for (int y = 0; y < galaxy_map.size(); y++) {
        cout << galaxy_map.at(y) << endl;

        for (int x = 0; x < galaxy_map.at(0).size(); x++) {
            if (galaxy_map.at(y).at(x) == '#') {
                star_coords.insert({{x, y}, counter});
                counter++;
            }
        }
    }

    // Map each star pair to a distance
    map<pair<int, int>, int> distances_map{};

    for (const auto& starting_point : star_coords) {
        cout << "Current Star: " << starting_point.second << endl;
        deque<pair<int, int>> to_check{starting_point.first};
        deque<int> distances{0};
        set<pair<int, int>> already_checked;

        int unchecked_galaxies{star_coords.size()};

        while (unchecked_galaxies) {
            int x = to_check.front().first;
            int y = to_check.front().second;

            //

            if (already_checked.count({x, y})) {
                to_check.pop_front();
                distances.pop_front();
                continue;
            }
            already_checked.insert({x, y});

            if (galaxy_map.at(y).at(x) == '#') {
                int star1 = min(starting_point.second, star_coords.at({x, y}));
                int star2 = max(starting_point.second, star_coords.at({x, y}));
                if (star1 != star2) {
                    pair<int, int> index{star1, star2};
                    // int target_num{find(star_coords.begin(), star_coords.end(), {x, y})};
                    if (distances_map.count(index)) {
                        if (distances.front() < distances_map.at(index)) {
                            distances_map.at(index) = distances.front();
                        }
                    } else {
                        distances_map.insert({index, distances.front()});
                    }
                }
                unchecked_galaxies -= 1;
            }

            if (x > 0) {
                to_check.push_back({x - 1, y});
                distances.push_back(distances.front() + 1);
            }
            if (x < galaxy_map.at(0).size() - 1) {
                to_check.push_back({x + 1, y});
                distances.push_back(distances.front() + 1);
            }
            if (y > 0) {
                to_check.push_back({x, y - 1});
                distances.push_back(distances.front() + 1);
            }
            if (y < galaxy_map.size() - 1) {
                to_check.push_back({x, y + 1});
                distances.push_back(distances.front() + 1);
            }

            to_check.pop_front();
            distances.pop_front();
        }
    }

    int sum{0};
    for (const auto& iter : distances_map) {
        cout << iter.first.first << " " << iter.first.second << ": " << iter.second << endl;
        sum += iter.second;
    }
    cout << "Sum: " << sum << endl;
}

void part_b() {
    string input{};
    vector<string> galaxy_map{};
    while (cin >> input) {
        galaxy_map.push_back(input);
        if (!count(input.begin(), input.end(), '#')) {
            galaxy_map.push_back(string(input.size(), '/'));
        }
    }

    // Iterate through every column
    for (int x{galaxy_map.at(0).size() - 1}; x > 0; x--) {
        bool no_hashtag = true;
        for (int y = 0; y < galaxy_map.size(); y++) {
            if (galaxy_map.at(y).at(x) == '#') {
                no_hashtag = false;
                break;
            }
        }
        if (no_hashtag) {
            for (int y = 0; y < galaxy_map.size(); y++) {
                galaxy_map.at(y).insert(galaxy_map.at(y).begin() + x, '/');
            }
        }
    }
    map<pair<int, int>, int> star_coords{};

    int counter{1};
    for (int y = 0; y < galaxy_map.size(); y++) {
        cout << galaxy_map.at(y) << endl;

        for (int x = 0; x < galaxy_map.at(0).size(); x++) {
            if (galaxy_map.at(y).at(x) == '#') {
                star_coords.insert({{x, y}, counter});
                counter++;
            }
            // cout << "X: " << x << endl;
        }
    }

    // Map each star pair to a distance
    map<pair<int, int>, int> distances_map{};

    for (const auto& starting_point : star_coords) {
        cout << "Current Star: " << starting_point.second << endl;
        deque<pair<int, int>> to_check{starting_point.first};
        deque<int> distances{0};
        set<pair<int, int>> already_checked;

        int unchecked_galaxies{star_coords.size()};

        while (unchecked_galaxies) {
            int x = to_check.front().first;
            int y = to_check.front().second;

            //

            if (already_checked.count({x, y})) {
                to_check.pop_front();
                distances.pop_front();
                continue;
            }
            already_checked.insert({x, y});

            if (galaxy_map.at(y).at(x) == '#') {
                int star1 = min(starting_point.second, star_coords.at({x, y}));
                int star2 = max(starting_point.second, star_coords.at({x, y}));
                if (star1 != star2) {
                    pair<int, int> index{star1, star2};
                    // int target_num{find(star_coords.begin(), star_coords.end(), {x, y})};
                    if (distances_map.count(index)) {
                        if (distances.front() < distances_map.at(index)) {
                            distances_map.at(index) = distances.front();
                        }
                    } else {
                        distances_map.insert({index, distances.front()});
                    }
                }
                unchecked_galaxies -= 1;
            }
            int extra_distance{1000000};

            if ((galaxy_map.at(y).at(x) == '/')) {
                if ((x > 0) && (galaxy_map.at(y).at(x - 1) != '/')) {
                    to_check.push_back({x - 1, y});
                    distances.push_back(distances.front() + extra_distance - 1);
                }
                if ((x < galaxy_map.at(0).size() - 1) && (galaxy_map.at(y).at(x + 1) != '/')) {
                    to_check.push_back({x + 1, y});
                    distances.push_back(distances.front() + extra_distance - 1);
                }
                if ((y > 0) && (galaxy_map.at(y - 1).at(x) != '/')) {
                    to_check.push_back({x, y - 1});
                    distances.push_back(distances.front() + extra_distance - 1);
                }
                if ((y < galaxy_map.size() - 1) && (galaxy_map.at(y + 1).at(x) != '/')) {
                    to_check.push_back({x, y + 1});
                    distances.push_back(distances.front() + extra_distance - 1);
                }
            } else {
                if (x > 0) {
                    to_check.push_back({x - 1, y});
                    distances.push_back(distances.front() + 1);
                }
                if (x < galaxy_map.at(0).size() - 1) {
                    to_check.push_back({x + 1, y});
                    distances.push_back(distances.front() + 1);
                }
                if (y > 0) {
                    to_check.push_back({x, y - 1});
                    distances.push_back(distances.front() + 1);
                }
                if (y < galaxy_map.size() - 1) {
                    to_check.push_back({x, y + 1});
                    distances.push_back(distances.front() + 1);
                }
            }

            to_check.pop_front();
            distances.pop_front();
        }
    }

    ll sum{0};
    for (const auto& iter : distances_map) {
        cout << iter.first.first << " " << iter.first.second << ": " << iter.second << endl;
        sum += iter.second;
    }
    cout << "Sum: " << sum << endl;
    // I just check to make sure that it won't go check an adjacent '/' (1m length row) if it already is one.
    // Luckily I can take advantage of the fact that there won't be 2 in a row to do this. If there were, life would be harder.
}

int main() {
    freopen("inputs/d11.txt", "r", stdin);
    // part_a();
    part_b();
}