#include <bits/stdc++.h>
#define ln '\n'
using namespace std;

typedef long long ll;

void part_a() {
    ll target = 0;
    cin >> target;

    vector<bool> odd_numbers(500, true);

    // for (int i = 3; i < odd_numbers.size(); i += 2) {
    //     if (odd_numbers[i] == true) {
    //         for (int x = i; x < odd_numbers.size(); x += i) {
    //             odd_numbers[i] = false;
    //             // cout << x << ln;
    //         }
    //         cout << i << ": " << odd_numbers[i] << ln;
    //     }
    // }

    vector<int> numbers(10000);
    for (int i = 0; i < numbers.size(); i++) numbers[i] = i * 2 + 1;
    // for (int i = 0; i < numbers.size(); i++) cout << numbers[i] << ln;
    // cout << ln << ln;

    for (int y = 1; y < numbers.size(); y++) {
        for (int x = numbers[y] - 1; x < numbers.size(); x += numbers[y] - 1) {
            numbers.erase(numbers.begin() + x);
        }
        // cout << numbers.at(y) << ln;
    }

    ll lesser_than_target = 1, larger_than_target = 0;
    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] < target) lesser_than_target = numbers[i];
        if (numbers[i] > target) {
            larger_than_target = numbers[i];
            break;
        }
    }
    cout << lesser_than_target << " " << larger_than_target << ln;
}  // Done in 30 mins. Passes all test cases.


int main() {
    freopen("inputs/q1.txt", "r", stdin);
    part_a();
    // part_b();
}