#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct dot {
    int y;
    int x;

    bool up_edge = false, down_edge = false, left_edge = false, right_edge = false;

    // Returns true if successful. Method to add an edge.
    bool add_edge(vector<vector<dot>>& dot_grid, bool player1) {
        if (player1) {
            if ((y > 0) && !up_edge) {
                up_edge = true;
                dot_grid[y - 1][x].down_edge = true;
                return true;

            } else if ((x < 5) && !right_edge) {
                right_edge = true;
                dot_grid[y][x + 1].left_edge = true;
                return true;

            } else if ((y < 5) && !down_edge) {
                down_edge = true;
                dot_grid[y + 1][x].up_edge = true;
                return true;

            } else if ((x > 0) && !left_edge) {
                left_edge = true;
                dot_grid[y][x - 1].right_edge = true;
                return true;
            }
        } else {
            if ((y > 0) && !up_edge) {
                up_edge = true;
                dot_grid[y - 1][x].down_edge = true;
                return true;

            } else if ((x > 0) && !left_edge) {
                left_edge = true;
                dot_grid[y][x - 1].right_edge = true;
                return true;

            } else if ((y < 5) && !down_edge) {
                down_edge = true;
                dot_grid[y + 1][x].up_edge = true;
                return true;

            } else if ((x < 5) && !right_edge) {
                right_edge = true;
                dot_grid[y][x + 1].left_edge = true;
                return true;
            }
        }
        return false;
    }
    bool update_squares(const vector<vector<dot>>& dot_grid, vector<vector<char>>& square_grid, char player, ll& player_score) {
        bool won_square = false;
        // Check top left square
        if ((x > 0) && (y > 0) && (square_grid[y - 1][x - 1] == '*')) {
            if ((up_edge && left_edge && dot_grid[y][x - 1].up_edge && dot_grid[y - 1][x].left_edge)) {
                player_score += 1;
                square_grid[y - 1][x - 1] = player;
                won_square = true;
            }
        }

        // Check top right square
        if ((x < 5) && (y > 0) && (square_grid[y - 1][x] == '*')) {
            if ((up_edge && right_edge && dot_grid[y][x + 1].up_edge && dot_grid[y - 1][x].right_edge)) {
                player_score += 1;
                square_grid[y - 1][x] = player;
                won_square = true;
            }
        }

        // Check bottom left edge
        if ((x > 0) && (y < 5) && (square_grid[y][x - 1] == '*')) {
            if ((down_edge && left_edge && dot_grid[y][x - 1].down_edge && dot_grid[y + 1][x].left_edge)) {
                player_score += 1;
                square_grid[y][x - 1] = player;
                won_square = true;
            }
        }

        // Check bottom right edge
        if ((x < 5) && (y < 5) && (square_grid[y][x] == '*')) {
            if ((down_edge && right_edge && dot_grid[y][x + 1].down_edge && dot_grid[y + 1][x].right_edge)) {
                player_score += 1;
                square_grid[y][x] = player;
                won_square = true;
            }
        }
        return won_square;
    }
};

void part_a() {
    // Construct a grid of dots to traverse
    vector<vector<dot>> dot_grid{};
    for (int y = 0; y < 6; y++) {
        dot_grid.push_back({});
        for (int x = 0; x < 6; x++) {
            dot_grid.at(y).push_back(dot{y, x});
        }
    }

    // Construct the square grid only for outputting later.
    vector<vector<char>> square_grid{};
    for (int y = 0; y < 5; y++) {
        square_grid.push_back({});
        for (int x = 0; x < 5; x++) {
            square_grid.at(y).push_back('*');
        }
    }

    // cout << dot_grid.at(5).at(0).y << endl;

    ll position1, modifier1, position2, modifier2, turns;
    cin >> position1 >> modifier1 >> position2 >> modifier2 >> turns;
    position1--;
    position2--;
    ll player_score1{0}, player_score2{0};

    // cout << "2 player positions! " << position1 << " " << position2 << endl;
    bool player1 = true;
    for (ll i = 0; i < turns; i++) {
        if (player1) {
            // cout << "2 player positions! " << position1 << " " << position2 << endl;
            // PLayer1 turn
            position1 = (position1 + modifier1) % 36;
            while (!dot_grid[(position1) / 6][(position1) % 6].add_edge(dot_grid, true)) {
                position1 = (position1 + 1) % 36;
            }
            // cout << (position1) / 6 << " " << (position1) % 6 << endl;
            // cout << "Position1: " << position1 << endl;
            if (!dot_grid[(position1) / 6][(position1) % 6].update_squares(dot_grid, square_grid, 'X', player_score1)) {
                player1 = false;
            }
        } else {
            // Player2 turn
            position2 = (position2 + modifier2) % 36;

            while (!dot_grid[(position2) / 6][(position2) % 6].add_edge(dot_grid, false)) {
                position2 = (position2 + 1) % 36;
                // cout << 2 << endl;
            }
            // cout << (position2) / 6 << " " << (position2) % 6 << endl;
            // cout << "Position2: " << position2 << endl;
            if (!dot_grid[(position2) / 6][(position2) % 6].update_squares(dot_grid, square_grid, 'O', player_score2)) {
                player1 = true;
            }
        }
    }
    for (const auto& itery : square_grid) {
        for (const auto& iterx : itery) {
            cout << iterx << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << player_score1 << " " << player_score2 << endl;
}
/*
Passes all test cases so it worth 24/24 points! :D I wrote 85% of this solution within 40m but I then went over the time by a LOT trying
to debug it :(... I also missed the clause at the front saying you can get chain moves. To explain the program: OOP carries hard today.

- Declare a struct for each dot object with its adjacent edges, x y coordinates, and 2 member functions for updating info
- Make a 2d vector that holds the grid of dot objects.
- Main gameloop in for loop that repeatedly calls the member functions to update edges and captured squares.
- Struct uses member variables like x y and edges to lookup information really easily within the functions.
- Run it for all the turns

This was quite the complex thing, but actually I'd say it could've been much worse. Or maybe I'm just getting used to solving these questionable
questions lmao
*/

int main() {
    freopen("inputs/q2.txt", "r", stdin);
    part_a();
    // part_b();
}