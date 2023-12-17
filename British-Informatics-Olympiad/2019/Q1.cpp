#include <math.h>

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

unsigned long long reverse_int(unsigned long long input) {
    unsigned long long output{0};
    while (input) {
        output *= 10;
        output += input % 10;
        input /= 10;
    }
    return output;
}

string reverse(string str) {
    string return_value{};
    for (long long i = str.length() - 1; i >= 0; i--) return_value += str[i];
    return return_value;
}

int main() {
    cout << "Enter Input: \n";
    while (true) {
        unsigned long long inp{12345};

        cin >> inp;

        if (inp < 10) {
            inp += 1;
            cout << "Answer: " << inp << "\n\n";

        } else {

            string num = to_string(inp);

            long long half1{stoll(num.substr(0, (num.size() + 1) / 2))};
            string half2{(num.substr((num.size() + 1) / 2, (num.size() / 2)))};
            cout << "1: " << stoll(num.substr(0, (num.size()) / 2)) << endl;
            cout << "2: " << stoll(reverse(num.substr((num.size() + 1) / 2, (num.size() / 2)))) << endl;

            if (stoll(num.substr(0, (num.size()) / 2)) <= stoll(reverse(num.substr((num.size() + 1) / 2, (num.size() / 2))))) {
                half1 += 1;
            }
            cout << "Half1: " << half1 << endl;

            num = to_string(half1) + half2;

            for (unsigned long long i{0}; i < (num.size() / 2); i++) {

                num[(num.size()) - 1 - i] = num.at(i);
            }

            cout << "Answer: " << num << "\n\n";
        }
    }
}

// Correct on every single test case except 234567890 -> 234575432 for some reason. Ahh well.
// This took me way longer than it should have. Really weird.
// I did eventually get an efficient solution that is mostly correct though.
