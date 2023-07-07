#include <iostream>
#include <string>
#include <vector>

// This is a working solution, however it is very inefficient. I will come back to optimize this.

using namespace std;

int main(){

    string input = "cabd"; // the parking arragement to input
    int index = 5; // Index of final preference to find
    cin >> input >> index;

    string taken(input.size(), ' ');
    char letter;
    vector<string> preferences_input;
    int x;

    for (int i; i < input.length(); i++){
        int index = input.find(97+i);
        // cout << index << endl;

        letter = 97 + i;
        taken[index] = letter;

        x = 1;

        while ((index - x >= 0) && (taken[index - x] != ' '))
        {
            taken[index-x] = letter;
            x++;
        }


        preferences_input.push_back(taken);

        for (int u = 0; u < preferences_input[i].length(); u++){
            if (preferences_input[i][u] != letter){
                preferences_input[i][u] = ' ';
            }
        }
    }
    

    vector<string> preferred_spots;

    int total = 1;
    string temp;

    for (size_t i = 0; i < preferences_input.size(); ++i){
        temp.clear();
        for (size_t u = 0; u < preferences_input[i].length(); u++)
        {
            if (preferences_input[i][u] != ' '){
                letter = 65 + u;
                temp += letter;
            }
        }
        preferred_spots.push_back(temp);
        total *= preferred_spots[i].length();
        cout << preferred_spots[i] << endl;
    }

    string output;
    cout << "Total: " << total << endl;
    for (size_t i = 0; i < preferred_spots.size(); ++i)
    {
        // Modulus divide index to remove repeats, then multiply by possible options, divide by total again to select character
        output += preferred_spots[i][((index - 1) % (total)) * preferred_spots[i].length() / total];
        cout << ((index -1) / (total / preferred_spots[i].length())) << endl;
        total /= preferred_spots[i].length();
        // I wrote this at 1am, am not entirely sure how it works either but it passes 9 test cases and fails 2
    }


    cout << output << endl;
    
}
