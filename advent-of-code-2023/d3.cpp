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
    freopen("inputs/d3.txt", "r", stdin);

    long total {};
    string input{};

    vector<string> matrix{{}};

    while (cin >> input){
        matrix.push_back(input);
        // cout << input << endl;
    }
    for (const auto&input:matrix){
        vector<int> numbs_on_row {};
        int num{0};
        char temp {'.'};
        for (const auto & iter: input){
            
            if (isdigit(iter)){
                num *= 10;
                num += iter-'0';
            }
            else {
                if(num>0){
                    if((temp != '.')||(iter != '.')){
                        if()
                        numbs_on_row.push_back(num);
                    }
                    num = 0;
                }
                temp = iter;
            }
        }
        if(num>0){
            if ((temp != '.')){
                numbs_on_row.push_back(num);
            }
            num = 0;
        }


        
        for (const auto& iter: numbs_on_row){
            cout << iter << " ";
            total += iter;
        }
        cout << endl;
    }
}