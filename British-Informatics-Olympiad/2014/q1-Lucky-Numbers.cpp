#include <bits/stdc++.h>
#define ln '\n'
using namespace std;

typedef long long ll;

void part_a() {
    ll target = 0;
    cin >> target;

    vector<bool> odd_numbers(500, true);

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
/*

Easy and simple algorithm. Just make a list of odd numbers and do the operation exactly as requested by the question. Remove all
the numbers whose index is a multiple of the value of the current odd number. Took me longer than normal because I attempted to
use a set, then a vector of booleans, and these incorrect approaches wasted a lot of good time :(. Otherwise pretty good.

*/

int main() {
    freopen("inputs/q1.txt", "r", stdin);
    part_a();
    // part_b();
}