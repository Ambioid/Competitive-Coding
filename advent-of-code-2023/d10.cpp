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
    vector<string> pipe_map{};
    string input{};
    int i{0};
    pair<int, int> var{};
    while (cin >> input) {
        pipe_map.push_back(input);
        if (find(pipe_map.at(i).begin(), pipe_map.at(i).end(), 'S') != pipe_map.at(i).end()) {
            var = {i, pipe_map.at(i).find('S')};
        }
        i++;
    }
    cout << "Location: " << var.first << var.second << endl;
    //

    //
    // initlaize BFS
    deque<pair<int, int>> to_check{};
    deque<int> distance_que{0, 0};
    set<pair<int, int>> already_checked;
    int map_size{pipe_map.size() - 1};

    if (var.first > 0 && pipe_map.at(var.first - 1).at(var.second) != '.') {
        to_check.push_back({var.first - 1, var.second});
    }
    if (var.first < map_size && pipe_map.at(var.first + 1).at(var.second) != '.') {
        to_check.push_back({var.first + 1, var.second});
    }
    if (var.second > 0 && pipe_map.at(var.first).at(var.second - 1) != '.') {
        to_check.push_back({var.first, var.second - 1});
    }
    if (var.second < map_size && pipe_map.at(var.first).at(var.second + 1) != '.') {
        to_check.push_back({var.first, var.second + 1});
    }

    while (to_check.size() > 1) {
        int y{to_check.front().first};
        int x{to_check.front().second};

        cout << y << " " << x << endl;

        if (already_checked.count(to_check.front())) {
            to_check.pop_front();
            continue;
        }

        // Check the adjacent pipes depending on pipe type. It ain't pretty, but it gets the job done.
        if (pipe_map.at(y).at(x) == '|') {
            if (y > 0) {
                to_check.push_back({y - 1, x});
            }
            if (y < map_size) {
                to_check.push_back({y + 1, x});
            }
        }

        else if (pipe_map.at(y).at(x) == '-') {
            if (x > 0) {
                to_check.push_back({y, x - 1});
            }
            if (x < map_size) {
                to_check.push_back({y, x + 1});
            }

        }

        else if (pipe_map.at(y).at(x) == 'L') {
            if (y > 0) {
                to_check.push_back({y - 1, x});
            }
            if (x < map_size) {
                to_check.push_back({y, x + 1});
            }
        }

        else if (pipe_map.at(y).at(x) == 'J') {
            if (y > 0) {
                to_check.push_back({y - 1, x});
            }
            if (x > 0) {
                to_check.push_back({y, x - 1});
            }
        }

        else if (pipe_map.at(y).at(x) == '7') {
            if (x > 0) {
                to_check.push_back({y, x - 1});
            }
            if (y < map_size) {
                to_check.push_back({y + 1, x});
            }
        }

        else if (pipe_map.at(y).at(x) == 'F') {
            if (y < map_size) {
                to_check.push_back({y + 1, x});
            }
            if (x < map_size) {
                to_check.push_back({y, x + 1});
            }
        }
        distance_que.push_back(distance_que.front() + 1);
        already_checked.insert(to_check.front());
        to_check.pop_front();
        distance_que.pop_front();
    }

    cout << "\nFurthest spot: " << to_check.front().first << " " << to_check.front().second << endl;
    cout << "Furthest Distance: " << distance_que.front() << endl;
}

void part_b() {
    vector<string> pipe_map{};
    string input{};
    int i{0};
    pair<int, int> var{};
    while (cin >> input) {
        pipe_map.push_back(input);
        if (find(pipe_map.at(i).begin(), pipe_map.at(i).end(), 'S') != pipe_map.at(i).end()) {
            var = {i, pipe_map.at(i).find('S')};
        }
        i++;
    }
    cout << "Location: " << var.first << var.second << endl;
    //

    //
    // initlaize BFS
    deque<pair<int, int>> to_check{};
    deque<int> distance_que{0, 0};
    set<pair<int, int>> already_checked;
    int map_size{pipe_map.size() - 1};

    if (var.first > 0 && pipe_map.at(var.first - 1).at(var.second) != '.') {
        to_check.push_back({var.first - 1, var.second});
    }
    if (var.first < map_size && pipe_map.at(var.first + 1).at(var.second) != '.') {
        to_check.push_back({var.first + 1, var.second});
    }
    if (var.second > 0 && pipe_map.at(var.first).at(var.second - 1) != '.') {
        to_check.push_back({var.first, var.second - 1});
    }
    if (var.second < map_size && pipe_map.at(var.first).at(var.second + 1) != '.') {
        to_check.push_back({var.first, var.second + 1});
    }

    while (to_check.size() > 1) {
        int y{to_check.front().first};
        int x{to_check.front().second};

        cout << y << " " << x << endl;

        if (already_checked.count(to_check.front())) {
            to_check.pop_front();
            continue;
        }

        // Check the adjacent pipes depending on pipe type. It ain't pretty, but it gets the job done.
        if (pipe_map.at(y).at(x) == '|') {
            if (y > 0) {
                to_check.push_back({y - 1, x});
            }
            if (y < map_size) {
                to_check.push_back({y + 1, x});
            }
        }

        else if (pipe_map.at(y).at(x) == '-') {
            if (x > 0) {
                to_check.push_back({y, x - 1});
            }
            if (x < map_size) {
                to_check.push_back({y, x + 1});
            }

        }

        else if (pipe_map.at(y).at(x) == 'L') {
            if (y > 0) {
                to_check.push_back({y - 1, x});
            }
            if (x < map_size) {
                to_check.push_back({y, x + 1});
            }
        }

        else if (pipe_map.at(y).at(x) == 'J') {
            if (y > 0) {
                to_check.push_back({y - 1, x});
            }
            if (x > 0) {
                to_check.push_back({y, x - 1});
            }
        }

        else if (pipe_map.at(y).at(x) == '7') {
            if (x > 0) {
                to_check.push_back({y, x - 1});
            }
            if (y < map_size) {
                to_check.push_back({y + 1, x});
            }
        }

        else if (pipe_map.at(y).at(x) == 'F') {
            if (y < map_size) {
                to_check.push_back({y + 1, x});
            }
            if (x < map_size) {
                to_check.push_back({y, x + 1});
            }
        }
        distance_que.push_back(distance_que.front() + 1);
        already_checked.insert(to_check.front());
        to_check.pop_front();
        distance_que.pop_front();
    }

    cout << "\nFurthest spot: " << to_check.front().first << " " << to_check.front().second << endl;
    cout << "Furthest Distance: " << distance_que.front() << endl;
}

int main() {
    freopen("inputs/d10.txt", "r", stdin);
    // part_a();
    part_b();
}