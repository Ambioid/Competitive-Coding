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
    freopen("inputs/d1.txt", "r", stdin);

    string a{};
    long long sum{0};

    while (cin >> a) {  // Repeats per line.
        int front{-1};
        int back{};

        for (const auto &iter : a) {
            if (isdigit(iter)) {
                if (front == -1) {
                    front = iter - '0';
                }

                back = iter - '0';
            }
        }

        sum += front * 10 + back;
        cout << sum << endl;
        // cout << front << " " << back << endl;
    }
}