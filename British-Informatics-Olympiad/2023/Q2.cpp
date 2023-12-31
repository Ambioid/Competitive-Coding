/*
My solution to Q2 of 2023 BIO. 
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <bitset>
#include <set>
#include <unordered_map>

using namespace std;

/* Probably not the most efficient way, but it should work completely fine. As I can guarantee that a pentomino would be at max 5x3 wide, I can safely
just brute force every combination possible without facing time penalty. This program I have written works by iterating through every box and checking for 
all valid combinations (Checks for collisions and edges), and then adds them with the pentomino it was working with. Then I take advantage of the fact that
C++ sets are automatically sorted, which means that all the pixels will always be in the same order and relative position, and offset them all so they all start
at the same place. This makes identical shapes exactly the same, which I then use another set to eliminate. I output the length of that set to get the final output.*/

int main(){
    // Didn't bother to add all of the pentominoes because it was too intensive. Hope that this isn't a problem in the actual exam..
    // I guess this also means I didn't do all test cases but I'm reasonably certain and also kinda done with this question I spent too long..
    unordered_map<char, set<vector<int>>> pentominoes{  {'F', {{0,1},{0,2},{1,0},{1,1},{2,1}}},
                                                        {'G', {{0,0},{0,1},{1,1},{1,2},{2,1}}},
                                                        {'I', {{0,0},{1,0},{2,0},{3,0},{4,0}}},
                                                        {'X', {{0,1},{1,0},{1,1},{1,2},{2,1}}}
                                                        };
    unordered_map<char, set<vector<int>>> pentomino_edges{   // Coords of spots it must touch for edges to meet
                                                            {'F', {{-1, 1}, {-1, 2}, {0,0}, {0,3}, {1,-1}, {1,2}, {2,0}, {2,2}, {3,1}}},
                                                            {'G', {{-1,0},{-1,1},{0,-1},{0,2},{1,0},{1,3},{2,0},{2,2},{3,1}}},
                                                            {'I', {{0,-1},{1,-1},{2,-1},{3,-1},{4,-1},{0,1},{1,1},{2,1},{3,1},{4,1},{-1,0},{5,0}}},
                                                            {'X', {{-1, 1}, {1,-1}, {1,3}, {3,1}}},
                                                            }; 

    string inp;
    cin >> inp;
    char p1{inp[0]}, p2{inp[1]};
    set<vector<int>> pentomino1 = pentominoes[p1];
    set<vector<int>> pentomino2 = pentominoes[p2];
    set<vector<int>> pentomino2_edges = pentomino_edges[p2];


    set<set<vector<int>>> solutions{}; // Set of possible combinations
    // vector<int> dimensions_x{5,3};
    int max_x = 5;
    int max_y = 3;
    for (int y{1-max_y}; y < max_y+1; y++){
        for (int x{1-max_x}; x < max_x+1; x++){
            bool noCollide = true;
            bool touchesEdge = false;
            set<vector<int>> current_solution{};

            // Iterate through all the blocks in pentamino to see if any collide.
            for (const auto& coord : pentomino1){
                vector<int> pos{x+coord[0], y+coord[1]};
                if (pentomino2.count(pos)){ // If collides
                    noCollide = false;   
                }
                if (pentomino2_edges.count(pos)){ // If touches edge
                    touchesEdge = true;   
                }

                //Create a set of coords that combines both the pentaminos
                current_solution.insert(coord);
                current_solution.insert({coord[0] + x, coord[1] + y});
            }

            if (noCollide && touchesEdge){
                vector<int> row_count{};

                int x_offset{ -(*current_solution.begin())[0] };
                int y_offset{ -(*current_solution.begin())[1] };
                
                auto iter1 = current_solution.begin();

                set<vector<int>> final_current_solution{};
                for (const auto iter1 : current_solution){
                    final_current_solution.insert({iter1[0]+x_offset, iter1[1]+y_offset});
                }
                solutions.insert(final_current_solution);
            }
        }
    }

    cout << "Correct Cominations (Without Duplicates): " << endl << solutions.size() << endl;
}

// Most definitely did not solve within 1h. Not even close.
