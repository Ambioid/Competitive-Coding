#include <algorithm>
#include <cstdio>
#include <deque>
#include <iostream>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
void part_a() {
    while (1) {
        deque<vector<vector<int>>> to_check = {{{}, {}, {}, {}}};
        vector<vector<int>> goal{};
        deque<int> prev_distance{0};

        goal = {{}, {}, {}, {}};
        vector<vector<int>> temp2{{}, {}, {}, {}};

        string a;

        // Get input into the first thing to check
        for (int y{0}; y < 4; y++) {
            cin >> a;
            for (int x = 0; x < a.size(); x++) {
                if (a[x] == '0') break;
                to_check[0][y].push_back(a[x] - '0');
            }
        }

        // Get the input into desired goal.
        for (int y{0}; y < 4; y++) {
            cin >> a;
            for (int x = 0; x < a.size(); x++) {
                if (a[x] == '0') break;
                goal[y].push_back(a[x] - '0');
            }
        }

        // Actual program starts here

        set<vector<vector<int>>> memo{};  // Make a memo tree that links a stack to its distance from the base case.

        vector<vector<int>> stack{to_check.front()};
        to_check.pop_front();
        int current_distance{prev_distance.front()};
        prev_distance.pop_front();

        while (stack != goal) {
            if (memo.count(stack)) {
                stack = to_check.front();
                to_check.pop_front();
                prev_distance.pop_front();
                current_distance = prev_distance.front();
                continue;
            }

            // iterate 12 times through 12 possibilities.
            for (int base_stack = 0; base_stack < 4; base_stack++) {
                if (stack[base_stack].empty()) {
                    continue;
                }
                for (int dest_stack = 0; dest_stack < 4; dest_stack++) {
                    // Don't move a block back to itself. Means there'll only ever be 3 iterations instead of 4.
                    if (dest_stack == base_stack) {
                        continue;
                    }
                    vector<vector<int>> temp{stack};

                    temp[dest_stack].push_back(temp[base_stack][temp[base_stack].size() - 1]);
                    temp[base_stack].pop_back();

                    to_check.push_back(temp);
                    prev_distance.push_back(current_distance + 1);

                    // +1 to distance
                }
            }

            // for(auto& iter1 : to_check.front()){
            //     std::cout << " ";
            //     for(auto& iter2 : iter1){
            //         std::cout << iter2;
            //     }

            // }
            // std::cout << endl;

            memo.insert(stack);
            stack = to_check.front();
            // to_check.erase(to_check.begin());
            to_check.pop_front();
            current_distance = prev_distance.front();
            // distance.erase(distance.begin());
            prev_distance.pop_front();
        }

        // You broke out of loop because your conditions are correct.

        std::cout << prev_distance.front() << endl;
    }
}

void part_b() {
    // while (1) {
    deque<vector<vector<int>>> to_check = {{{1}, {2}, {3}, {4}}};
    deque<int> prev_distance{0};

    vector<vector<int>> temp2{{}, {}, {}, {}};

    string a;
    // Actual program starts here

    set<vector<vector<int>>> memo{};  // Make a memo tree that links a stack to its distance from the base case.

    vector<vector<int>> stack{to_check.front()};
    int current_distance{prev_distance.front()};
    prev_distance.pop_front();

    int counter{0};
    while (!to_check.empty()) {
        if (memo.count(stack)) {
            stack = to_check.front();
            to_check.pop_front();
            current_distance = prev_distance.front();
            prev_distance.pop_front();
            continue;
        }

        int possible_moves{0};
        // iterate 12 times through 12 possibilities.
        for (int base_stack = 0; base_stack < 4; base_stack++) {
            if (stack[base_stack].empty()) {
                continue;
            }
            for (int dest_stack = 0; dest_stack < 4; dest_stack++) {
                // Don't move a block back to itself. Means there'll only ever be 3 iterations instead of 4.
                if (dest_stack == base_stack) {
                    continue;
                }

                vector<vector<int>> temp{stack};

                temp[dest_stack].push_back(temp[base_stack][temp[base_stack].size() - 1]);
                temp[base_stack].pop_back();

                to_check.push_back(temp);
                prev_distance.push_back(current_distance + 1);
                possible_moves += 1;

                // +1 to distance
            }
        }
        // cout << possible_moves << endl;
        if (possible_moves == 9) counter++;

        memo.insert(stack);
        stack = to_check.front();
        // to_check.erase(to_check.begin());
        to_check.pop_front();
        current_distance = prev_distance.front();
        // distance.erase(distance.begin());
        prev_distance.pop_front();
    }

    // Returns solution of 288 (Correct).
    // Checks through every possible game state until it has exhausted this list, and while doing so also checks how many possible
    // Moves you can make from each state.

    std::cout << counter << endl;
}

void part_c() {
    deque<vector<vector<int>>> to_check = {{{1}, {2}, {3}, {4}}};
    deque<int> prev_distance{0};

    // Actual program starts here

    set<vector<vector<int>>> memo{};  // Make a memo tree that links a stack to its distance from the base case.

    // to_check.pop_front();
    int current_distance{prev_distance.front()};
    prev_distance.pop_front();

    int distance_2_counter{};
    int distance_4_counter{};

    while (!to_check.empty()) {
        vector<vector<int>> stack{to_check.front()};
        if (memo.count(stack)) {
            stack = to_check.front();
            current_distance = prev_distance.front();
            to_check.pop_front();
            prev_distance.pop_front();
            continue;
        }
        if (prev_distance.front() <= 2) {
            distance_2_counter++;
        }
        if (prev_distance.front() <= 4) {
            distance_4_counter++;
        }

        // iterate 12 times through 12 possibilities.
        for (int base_stack = 0; base_stack < 4; base_stack++) {
            if (stack[base_stack].empty()) {
                continue;
            }
            for (int dest_stack = 0; dest_stack < 4; dest_stack++) {
                // Don't move a block back to itself. Means there'll only ever be 3 iterations instead of 4.
                if (dest_stack == base_stack) {
                    continue;
                }
                vector<vector<int>> temp{stack};

                temp[dest_stack].push_back(temp[base_stack][temp[base_stack].size() - 1]);
                temp[base_stack].pop_back();

                to_check.push_back(temp);
                prev_distance.push_back(current_distance + 1);

                // +1 to distance
            }
        }

        for (auto& iter1 : to_check.front()) {
            std::cout << " ";
            for (auto& iter2 : iter1) {
                std::cout << iter2;
            }
        }
        std::cout << endl;

        memo.insert(stack);
        stack = to_check.front();
        // to_check.erase(to_check.begin());
        to_check.pop_front();
        current_distance = prev_distance.front();
        // distance.erase(distance.begin());
        prev_distance.pop_front();
    }

    // You broke out of loop because your conditions are correct.

    std::cout << distance_2_counter << " " << distance_4_counter << endl;
    // }
}

/*void part_d() {
    // while (1) {
    deque<vector<vector<int>>> to_check = {{{8}, {0}, {0}, {0}, {0}, {0}, {0}, {0}}};
    vector<vector<int>> goal{};
    deque<int> prev_distance{0};

    goal = {{}, {}, {}, {}};
    vector<vector<int>> temp2{{}, {}, {}, {}};

    string a;

    // // Get input into the first thing to check
    // for (int y{0}; y < 4; y++) {
    //     cin >> a;
    //     for (int x = 0; x < a.size(); x++) {
    //         if (a[x] == '0') break;
    //         to_check[0][y].push_back(a[x] - '0');
    //     }
    // }

    // // Get the input into desired goal.
    // for (int y{0}; y < 4; y++) {
    //     cin >> a;
    //     for (int x = 0; x < a.size(); x++) {
    //         if (a[x] == '0') break;
    //         goal[y].push_back(a[x] - '0');
    //     }
    // }

    // Actual program starts here

    set<vector<vector<int>>> memo{};  // Make a memo tree that links a stack to its distance from the base case.

    vector<vector<int>> stack{to_check.front()};
    to_check.pop_front();
    int current_distance{prev_distance.front()};
    prev_distance.pop_front();

    while (stack != goal) {
        if (memo.count(stack)) {
            stack = to_check.front();
            to_check.pop_front();
            prev_distance.pop_front();
            current_distance = prev_distance.front();
            continue;
        }

        for (int base_stack = 0; base_stack < 8; base_stack++) {
            if (stack[base_stack].empty()) {
                continue;
            }

            for (int dest_stack = 0; dest_stack < 8; dest_stack++) {
                // Don't move a block back to itself. Means there'll only ever be 7 iterations instead of 8.
                if (dest_stack == base_stack) {
                    continue;
                }
                vector<vector<int>> temp{stack};

                temp[dest_stack].push_back(temp[base_stack][temp[base_stack].size() - 1]);
                temp[base_stack].pop_back();

                to_check.push_back(temp);
                prev_distance.push_back(current_distance + 1);

                // +1 to distance
            }
        }

        // for(auto& iter1 : to_check.front()){
        //     std::cout << " ";
        //     for(auto& iter2 : iter1){
        //         std::cout << iter2;
        //     }

        // }
        // std::cout << endl;

        memo.insert(stack);
        stack = to_check.front();
        // to_check.erase(to_check.begin());
        to_check.pop_front();
        current_distance = prev_distance.front();
        // distance.erase(distance.begin());
        prev_distance.pop_front();
    }

    // You broke out of loop because your conditions are correct.

    std::cout << prev_distance.front() << endl;
    // }
}*/

int main() {
    part_a();
    // part_b();
    // part_c();
}