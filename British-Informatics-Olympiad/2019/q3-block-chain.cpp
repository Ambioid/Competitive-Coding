#include <algorithm>
#include <cstdio>
#include <deque>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// void solve_q1(std::unordered_map<vector<int>, vector<vector<int>>>& adjacency_list, vector<int> number){

// }


int main() {
    while (true) {
        int n{6};
        string temp{"123456"};

        cout << "\nEnter Input: \n";
        cin >> n >> temp;


        vector<int> number{};


        for (const char& iter : temp) {
            number.push_back(iter - '0');
        }
        vector<int> original_number = number;

        map<vector<int>, set<vector<int>>> adjacency_list = {{number, {}}};

        // Loop to check for all possible variations and put them into an adjacency list.
        deque<vector<int>> to_check{number};
        while (to_check.empty() == false) {
            number = to_check.front();

            // Iterate through all the digits and perform swaps where valid.
            for (int i{0}; i < n - 1; i++) {
                int temp_max{max(number[i], number[i + 1])};
                int temp_min{min(number[i], number[i + 1])};
                // If either i or i-1 is within the value range of the pair.
                if (((i > 1) && ((number.at(i - 1) < temp_max) && (number.at(i - 1) > temp_min))) || (i < (number.size() - 2) && ((number.at(i + 2) < temp_max) && (number.at(i + 2) > temp_min)))) {
                    // Does the swap on a copy of the number.
                    vector<int> new_variation{number};
                    int temp = new_variation.at(i);
                    new_variation.at(i) = new_variation.at(i + 1);
                    new_variation.at(i + 1) = temp;


                    // If it's not in the list, add a new entry to the adjacency list
                    if (adjacency_list.count(new_variation) == 0) {
                        // Adds the new variation into the adjancency list and updates its link.
                        adjacency_list.insert({new_variation, {number}});
                        to_check.push_back(new_variation);
                    }
                    adjacency_list[number].insert(new_variation);
                }
            }
            to_check.pop_front();
        }
        // Deals with the edge-case that there are NO other valid permutations.
        if (adjacency_list.size() == 1) {
            cout << "Distance: 0\n";
        } else {
            // cout << "New Variation: \n";
            // for (const auto& iter1 : adjacency_list){
            //     for (const auto & iter2: iter1.first){
            //         cout << iter2;
            //     }
            //     cout << ": ";
            //     for (const auto& iter2 : iter1.second){
            //         for (const auto& iter3: iter2){
            //             cout << iter3;
            //             }
            //         cout << " ";
            //         }

            //     cout << endl;
            // }
            // cout << "\n";

            // Traverse through them twice to find the furthest point.


            // QUeue of things to search and their distance.
            deque<vector<int>> to_search = {original_number};
            set<vector<int>> already_searched{to_search.front()};
            // vector<int> furthest_node {};

            // // do a binary search through entire graph to find furthest away from random point....
            // while (to_search.empty() == false){
            //     for (const auto iter: adjacency_list.at(to_search.front()) ){
            //         if (already_searched.count(iter) == 0){
            //             to_search.push_back(iter);
            //             already_searched.insert(iter);
            //             furthest_node = iter;
            //         }
            //     }
            //     to_search.pop_front();
            // }

            // // Re-assign it to be just the furthest node from last loop
            // to_search ={furthest_node};
            // already_searched = {furthest_node};
            deque<int> distances_que = {0};
            int furthest_distance{0};

            // ..... And then use this old furthest point to find the real furthest point.
            while (to_search.empty() == false) {
                for (const auto iter : adjacency_list.at(to_search.front())) {
                    if (already_searched.count(iter) == 0) {
                        to_search.push_back(iter);
                        already_searched.insert(iter);
                        distances_que.push_back(distances_que.front() + 1);
                        furthest_distance = max(distances_que.front() + 1, furthest_distance);
                    }
                }
                to_search.pop_front();
                distances_que.pop_front();
            }

            cout << "Furthest Distance: " << furthest_distance << endl;
        }
    }
}

// Fails: 7 2756413, 8 51438672, 8 51432687, 9 547389126
