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
    string input{"ATTCGGGA"};
    cin >> input;

    char prev_letter{};
    long longest{1};
    long current_length{1};
    for (const auto& iter: input){
        if(iter == prev_letter){
            current_length+=1;
            longest = max(current_length, longest);
        }
        else{
            current_length=1;
        }
        prev_letter = iter;
    }
    cout << longest;
}