#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <array>

using namespace std;

// This is an incomplete solution. I have solved the 1st part of it with the skirmishing mechanic, but was unable to finish the second part with the feuds.
// May return to this again in the future, but keeping it here anyways.

array<array<int, 6>, 25> grid; // Make a grid of 25 hexagons with 6 sides each
int red_edge = 0;
int blue_edge = 5;
int red_pos = 0;
int blue_pos = 24;
unordered_map<int, int> hex_offset = {{0, -4}, {1, 1}, {2, 6}, {3, 5}, {4, -1}, {5, -5}};

int red_claimed = 0;
int blue_claimed = 0;

void print_grid(array<array<int, 6>, 25> grid){
    for (int y = 0; y < 25; y++)
    {
        int sum = 0;
        if (y % 5 == 0)
        {
            cout << endl;
        }
        
        for (int x = 0; x < 6; x++)
        {
            sum += grid[y][x];

            // cout << grid[y][x];
        }
        cout << " ";
        if (sum > 0)
        {
            cout << 1;
        }
        else if (sum < 0)
        {
            cout << 2;
        }
        else
        {
            cout << 0;
        }
    }
    cout << endl;
}

void count_claimed(array<array<int, 6>, 25> grid){
    red_claimed = 0;
    blue_claimed = 0;
    for (int y = 0; y < 25; y++)
    {
        int sum = 0;
        if (y % 5 == 0)
        {
            cout << endl;
        }

        for (int x = 0; x < 6; x++)
        {
            sum += grid[y][x];

            // cout << grid[y][x];
        }
        cout << " ";
        if (sum > 0)
        {
            red_claimed += 1;
        }
        else if (sum < 0)
        {
            blue_claimed += 1;
        }
    }
}

void calc_skirmish(int skirm_count, int red_range, int blue_range){



    int edge = red_edge;
    int pos = red_pos;
    int range = red_range;
    int claimant = 1; // 1 represents red, -1 represents blue, 0 is neither.

    int other_edge;
    int other_pos;
    

    for (int y = 0; y < 25; y++){
        for (int x = 0; x < 6; x++){
            grid[y][x] = 0;
        }
    }
    cout << endl;

    for (int i = 0; i < skirm_count; i++){ // One skirmish step.
        for (int team = 0; team < 2; team++){
            if (team == 0){
                edge = red_edge;
                pos = red_pos;
                range = red_range;
                claimant = 1; // 1 represents red, -1 represents blue, 0 is neither.
            }
            else{
                edge = blue_edge;
                pos = blue_pos;
                range = blue_range;
                claimant = -1; // 1 represents red, -1 represents blue, 0 is neither.
            }
        
        grid[pos][edge] = claimant; 

        other_edge = edge + 3;
        if (other_edge > 5)
        {
            other_edge -= 6;
        }

        other_pos = pos + hex_offset[edge];

        if ((other_pos > -1) && (other_pos < 25) && !((pos % 5 == 0) && (edge > 2)) && !(((pos + 1) % 5 == 0) && (edge < 3)))
        {
            cout << endl
                 << "Secondary edge changed";
            grid[other_pos][other_edge] = claimant;
        }
        cout << endl
             << edge << " " << pos;
        cout << endl
             << other_edge << " " << other_pos;
        print_grid(grid);


        edge += 1;
        if (edge > 5){
            edge -= 6;
        }
        pos += range;
        if (pos > 24)
        {
            pos -= 25;
        }

        if (team == 0)
        {
            red_edge = edge;
            red_pos = pos;
        }
        else
        {
            blue_edge = edge;
            blue_pos = pos;
        }
    }}


    print_grid(grid);
}


void calc_feud(int feud_count){
    // unordered_map<int, int> hex_offset2 = {{0, -4}, {1, 1}, {2, 6}, {3, 5}, {4, -1}, {5, -5}};
    int claimant;
    int other_edge;
    int other_pos;

    for (int i = 0; i < feud_count; i++){ // One feud step.
    for (int team = 0; team < 2; team++){
        if (team == 0){
            claimant = 1; // 1 represents red, -1 represents blue, 0 is neither.
        }
        else{
            claimant = -1; // 1 represents red, -1 represents blue, 0 is neither.
        }

        int best_edge;
        int best_hex;
        array<array<int, 6>, 25> potential_grid; // Make a grid of 25 hexagons with 6 sides each

        for (int pos = 0; pos < 25; pos++){       // Iterate through every hex
            for (int edge = 0; edge < 6; edge++){ // Iterate through every edge of hex
                potential_grid = grid;
                potential_grid[pos][edge] = claimant;

                other_edge = edge + 3;
                if (other_edge > 5){
                    other_edge -= 6;
                }

                other_pos = pos + hex_offset[edge];

                if ((other_pos > -1) && (other_pos < 25) && !((pos % 5 == 0) && (edge > 2)) && !(((pos + 1) % 5 == 0) && (edge < 3))){
                    potential_grid[other_pos][other_edge] = claimant;
                }
                count_claimed(potential_grid);

                // If red and red has the most claimed by this move
                if ((team = 0) &&(red_claimed == 2)){
                    grid[pos][edge] = claimant;
                    other_edge = edge + 3;
                    if (other_edge > 5){
                        other_edge -= 6;
                    }

                    other_pos = pos + hex_offset[edge];

                    if ((other_pos > -1) && (other_pos < 25) && !((pos % 5 == 0) && (edge > 2)) && !(((pos + 1) % 5 == 0) && (edge < 3))){
                        grid[other_pos][other_edge] = claimant;
                    }
                    return;
                }
            }
        }
    }
    }
}

int main(){
    int red_range, blue_range, skirm_count, feud_count;
    red_range = 9, blue_range = 3, skirm_count = 3, feud_count = 1;
    // cin >> red_range >> blue_range >> skirm_count >> feud_count;

    cout << red_range << blue_range << skirm_count << feud_count << endl;

    calc_skirmish(skirm_count, red_range, blue_range);

    calc_feud(feud_count);
    
}
