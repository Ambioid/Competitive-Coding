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
     
    deque< vector<vector<int>>> to_check{};
    vector<vector<int>> goal{};
    deque<int> prev_distance{0};

    // to_check = {{{1,2,3,4}, {}, {}, {}}};
    // goal = {{4,3,2,1}, {}, {}, {}};

    // to_check = {{{}, {}, {}, {}}};
    goal = {{}, {}, {}, {}};
    vector<vector<int>> temp2{{}, {}, {}, {}};
    
    string a, b, c, d;
    cin >> a >> b >> c >> d;


    // Annoyingly dry and repeated code to get user input but I can't think of an easier way to do this..
    for(int i = 0; i < a.size(); i++){
        if (a[i] == '0')break;
        temp2[0].push_back(a[i]-'0');
    }
    for(int i = 0; i < b.size(); i++){
        if (b[i] == '0')break;
        temp2[1].push_back(b[i]-'0');
    }
    for(int i = 0; i < c.size(); i++){
        if (c[i] == '0')break;
        temp2[2].push_back(c[i]-'0');
    }
    for(int i = 0; i < d.size(); i++){
        if (d[i] == '0')break;
        temp2[3].push_back(d[i]-'0');
    }


    to_check = {temp2};
    
    cin >> a >> b >> c >> d;
    for(int i = 0; i < a.size(); i++){
        if (a[i] == '0')break;
        goal[0].push_back(a[i]-'0');
    }
    for(int i = 0; i < b.size(); i++){
        if (b[i] == '0')break;
        goal[1].push_back(b[i]-'0');
    }
    for(int i = 0; i < c.size(); i++){
        if (c[i] == '0')break;
        goal[2].push_back(c[i]-'0');
    }
    for(int i = 0; i < d.size(); i++){
        if (d[i] == '0')break;  
        goal[3].push_back(d[i]-'0');
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

                
                // Add a distance
                // Add the new thing to check

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
