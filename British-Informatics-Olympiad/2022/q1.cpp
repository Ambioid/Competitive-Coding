#include <iostream>
#include <string>

using namespace std;
typedef long long ll;
string decrypt(string str2) {
    char n;
    for (int i = str2.length() - 1; i > 0; i--) {
        n = str2[i] - str2[i - 1] + 64;

        if (n < 65) {
            n += 26;
        }
        // cout << n << endl;
        str2[i] = n;
    }
    return str2;
}
string encrypt(string str) {
    char n;
    for (int i = 1; i < str.length(); i++) {
        n = str[i] + str[i - 1] - 64;

        if (n > 90) {
            n -= 26;
        }
        // cout << n << endl;
        str[i] = n;
    }
    // cout << str << endl;
    return str;
}

int part_c() {
    string str = "OLYMPIAD";
    string str2 = str;
    cout << endl;

    str2 = encrypt(str2);
    int i = 1;
    while (str != str2) {
        i++;
        str2 = encrypt(str2);
    }
    cout << "Iterations until it returns to original: " << i << endl;
    return i;
}

void part_d() {
    cout << "Enter string to decrypt please" << endl;

    string str = "AAA";
    // cin >> str;
    ll counter = 0;
    for (int a = 'A'; a < 'Z' + 1; a++) {
        for (int b = 'A'; b < 'Z' + 1; b++) {
            for (int c = 'A'; c < 'Z' + 1; c++) {
                str = "";
                str += (a);
                str += (b);
                str += (c);
                string new_str = encrypt(str);
                ll iterations = 1;
                while (str != new_str) {
                    new_str = encrypt(new_str);
                    iterations++;
                }
                if (999999999999ll % iterations == 0) {
                    cout << str << endl;
                    counter++;
                }
            }
        }
    }

    cout << counter << endl;
}

int main() {
    string input{};
    cin >> input;
    cout << decrypt(input) << endl;  //
    // part_c();
    // part_d();
}
