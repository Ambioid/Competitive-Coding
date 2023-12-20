#include <algorithm>
#include <cstdio>
#include <deque>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

string swap(string boxes) {
    // cout << "Function Output: " <<boxes << endl;
    char temp = boxes[0];
    boxes[0] = boxes[1];
    boxes[1] = temp;

    return boxes;
}

int main() {
    while (true) {
        string goal{"ACBD"};

        cin >> goal;

        // cout << goal << endl;

        deque<string> next_states{"A"};
        deque<unsigned long> steps_counter{1};

        unordered_set<string> already_checked{};

        // Main loop below.
        while (next_states.front() != goal) {
            if (already_checked.count(next_states.front())) {
                next_states.pop_front();
                steps_counter.pop_front();
                continue;
            }

            string temp{next_states.front()};

            // Action 1: Add more chars if not enough
            if (temp.size() < goal.size()) {
                next_states.push_back(temp + char(temp.size() + 'A'));
                steps_counter.push_back(steps_counter.front() + 1);
            }

            // Action 2: Swap first 2
            next_states.push_back(swap(temp));

            // Action 3: Rotate string left
            rotate(temp.begin(), temp.begin() + 1, temp.end());
            next_states.push_back(temp);

            // Add the new step counts as well
            steps_counter.push_back(steps_counter.front() + 1);
            steps_counter.push_back(steps_counter.front() + 1);

            // Update the lists
            already_checked.insert(next_states.front());
            next_states.pop_front();
            steps_counter.pop_front();

            // cout << next_states.front() << " " << steps_counter.front() << "\n";
        }

        cout << steps_counter.front() << endl;
    }
}

/* Solved this question in 45 minutes. I would consider it quite easy, but I was slowed down considerably by not being familiar with C++ strings.

This solves 15/15 test cases, returns a solution within 1 second, and gets all 24 points.

Works on a breadth-first search of all possible combinations, each loop adds the 2/3 possible next steps and compares if it's the correct step, but
also skips if it has been checked before. This is fast enough to pass all test cases, even if I check all the incorrect combinations, because there are
not too many combinations. Pretty sure this scales exponentially, but some exponentials are smaller than others.

*/