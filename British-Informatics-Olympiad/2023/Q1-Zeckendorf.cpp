#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/* Algorithm Explained:
Simple Greedy algorithm with 2 loops: First it loops up to the max value (value of the target)
and then it works backwards from there, subtracting the maximum value it can subtract, and then
moving on to the next. This is efficient and runs in O(n) time, and is guaranteed to find shortest
sequence because it'll always target the largest value first. This is a greedy algorithm.
    */

void part_a() {
    // while (true) {
    int target{};
    vector<long long> fib{1, 1};
    vector<long long> sum{};
    // cout << fib[fib.size()-1] << endl;
    cout << "Insert Input: " << endl;
    cin >> target;
    while ((fib[fib.size() - 1] < target)) {
        fib.push_back(fib[fib.size() - 2] + fib[fib.size() - 1]);
        // cout << fib[fib.size()-1] << endl;
    }

    for (int i{fib.size() - 1}; i > 0; i--) {
        if (fib[i] <= target) {
            target -= fib[i];
            sum.push_back(fib[i]);
        }
    }
    cout << "Output:" << endl;
    for (auto& it : sum) {
        cout << it << " ";
    }
    cout << endl;
}

void part_b() {
    vector<long long> fib{1, 1};

    int target{1000000};

    // Solution to part B: 832040
    while ((fib[fib.size() - 1] < 1000000)) {
        // cout << fib[fib.size() - 1] << endl;
        fib.push_back(fib[fib.size() - 2] + fib[fib.size() - 1]);
    }
    cout << fib[fib.size() - 2] << endl;
}

void part_c() {
    vector<long long> fib{1, 1};

    long long target{53316291173};

    long long count{0};
    while ((fib[fib.size() - 1] < target)) {
        // cout << fib[fib.size() - 1] << endl;
        fib.push_back(fib[fib.size() - 2] + fib[fib.size() - 1]);
        count++;
    }

    long long total{};
    for (int x = 0; x < count; x++) {
        for (int y = x + 2; y < count; y++) {
            for (int z = y + 2; z < count; z++) {
                total += 1;
            }
        }
    }
    cout << total << endl;
}

int main() {
    // part_a();
    // part_b();
    part_c();
}

// Did Q1a 24 minutes (36:25 left) (could have easily been faster with more C++ Proficcency)
// Did Q1b shortly after (10 mins I'd say?)
// Spent more time trying to do the last 2 (went until 54m) and did not get them finished.
