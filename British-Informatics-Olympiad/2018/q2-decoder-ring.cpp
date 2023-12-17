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
    while (true){
    int n{5};
    string plain_text { "ABCD"};
    cout << "Input:\n";
    cin >> n >> plain_text;

    n = (n%26)-1;
    vector<int> letters = {};
    for(int i{0};i<26;i++){
        letters.push_back(i);
    }
    string dial_2 {};
    int temp_pos{0};
    while (letters.empty() == false){
        // cout << "Temp Pos: "<< temp_pos+n << endl;
        // dial_2.push_back(letters.at(temp_pos));
        temp_pos = (temp_pos+n)%letters.size();
        dial_2 += char(letters.at(temp_pos)+'A');
        letters.erase(letters.begin()+temp_pos);
    }


    // string dial_1 {};
    // for(int i{0};i<26;i++){
    //     dial_1.push_back(i+'A');
    // }
    
    // cout << dial_1 << endl;
    // cout << dial_2 << endl;
    string output{};
    int position{0};

    for (const auto& iter : plain_text){
        output += char(dial_2.at((iter+position-'A')%26));
        position +=1;
        
    }
    cout << string{dial_2.begin(), dial_2.begin()+6} << endl;; 
    cout << output << endl;
    
    

}}

// Fails 27 ABCDEF, 31 ELEPHANT, 999999 MOON
