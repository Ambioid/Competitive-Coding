#include <iostream>
#include <string>
#include <array>
#include <algorithm>

using namespace std;

// This solution works for 8/11 test cases, am not sure why it fails on the last 3. Mostly works though...?


bool pat_check(string str){
    // cout << str << endl;
    if (str.length() == 1){
        return true;
    }

    for (int halfway = 1; halfway < str.length(); halfway ++){
    // int halfway = (str.length() + 1) / 2;
    int lowest = 90;
    int highest = 0;
    for (int i = 0; i < halfway; i++){ // 0 to halfway (rounded up)
        // cout << str[i];
        if (str[i] > highest){
            highest = str[i];
        }
    }
    // cout << endl;
    for (int i = halfway; i < str.length(); i++)    { // halfway to end of string
        // cout << str[i];
        if (str[i] < lowest){
                lowest = str[i];
            }
    }
    // cout << endl;
    if (highest > lowest){ // Check if highest in loop1 is later than lowest in loop 1
            string substring1 = str.substr(0, halfway);
            reverse(substring1.begin(), substring1.end());
            string substring2 = str.substr(halfway, str.length());
            reverse(substring2.begin(), substring2.end());


            if (pat_check(substring1) && pat_check(substring2)){
                // cout << "Substrings: " << substring1 << ", " << substring2 << endl;

                return true;
            }
    }
    }
        // cout << highest << lowest << endl;
        // cout << "False:" << endl;
        return false;
    
    
}

int main(){
    array<string, 3> s = {"DE", "C"};
    // while (true){
    cin >> s[0] >> s[1]; 
    s[2] = s[0] + s[1];

    // cout << s[0] << ", " << s[1] << ", " << s[2] << endl;

    for (int i = 0; i < 3; i++){
        // cout << s[i] << endl;
        if (pat_check(s[i])){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
        cout << endl;
    }    
    // }

    return 1;
}
