#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <unordered_map>
#include <set>
#include <deque>

using namespace std;

int main(){
    while (1){
     
    deque< vector<vector<int>>> to_check = {{{}, {}, {}, {}}};
    vector<vector<int>> goal{};
    deque<int> prev_distance{0};

    goal = {{}, {}, {}, {}};
    vector<vector<int>> temp2{{}, {}, {}, {}};
    
    string a;

    // Get input into the first thing to check
    for(int y{0}; y < 4; y++){
        cin >> a;
        for(int x = 0; x < a.size(); x++){
            if (a[x] == '0')break;
            to_check[0][y].push_back(a[x]-'0');
        }
    }

    // Get the input into desired goal.
    for(int y{0}; y < 4; y++){
        cin >> a;
        for(int x= 0; x < a.size(); x++){
            if (a[x] == '0')break;
            goal[y].push_back(a[x]-'0');
        }
    }

    // std::cout << "Printing temp front:" << endl;
    // for(auto& iter1 : temp2){
    //         for(auto& iter2 : iter1){
    //             std::cout << iter2;
    //         }
    //         std::cout << " ";

    //     }
    //     std::cout << endl;

    // Actual program starts here

    set<vector<vector<int>>> memo{}; //Make a memo hash tree that links a stack to its distance from the base case.

    vector<vector<int>> stack{to_check.front()};
    to_check.pop_front();
    int current_distance{prev_distance.front()};
    prev_distance.pop_front();
    
    while (stack != goal){

        
        if (memo.count(stack)){
            stack = to_check.front();
            to_check.pop_front();
            current_distance = prev_distance.front();
            prev_distance.pop_front();
            continue;
        }

        // iterate 12 times through 12 possibilities.
        for (int base_stack = 0; base_stack < 4; base_stack++ ){
            if (stack[base_stack].empty()){
                continue;
            }
            for (int dest_stack = 0; dest_stack < 4; dest_stack++ ){
                // Don't move a block back to itself. Means there'll only ever be 3 iterations instead of 4.
                if (dest_stack == base_stack){
                    continue;
                }
                vector<vector<int>> temp{stack};

                
                temp[dest_stack].push_back(temp[base_stack][temp[base_stack].size()-1]);
                temp[base_stack].pop_back();

                to_check.push_back(temp);
                prev_distance.push_back(current_distance+1);

                // +1 to distance
            }
        }

        
        // for(auto& iter1 : to_check.front()){
        //     std::cout << " ";
        //     for(auto& iter2 : iter1){
        //         std::cout << iter2;
        //     }

        // }
        // std::cout << endl;

        
        memo.insert(stack);
        stack = to_check.front();
        // to_check.erase(to_check.begin());
        to_check.pop_front();
        current_distance = prev_distance.front();
        // distance.erase(distance.begin());
        prev_distance.pop_front();
    }

    // You broke out of loop because your conditions are correct.

    std::cout << prev_distance.front() << endl;


    
}}
