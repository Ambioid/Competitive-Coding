#include <iostream>
#include <string>
#include <vector>

// This is a working solution, however it is very inefficient. I will come back to optimize this.

using namespace std;
int iterations = 0;
vector<string> rebuild(vector<string> output, vector<string> preferred_spots, string current, string letter, int level, int index)
{
    if (output.size() > index){
        return output;
    }
    current += letter;
    if (level >= preferred_spots.size())
    {
        output.push_back(current);
        return output;
    }
    // vector<string> strings;
    for (size_t i = 0; i < preferred_spots[level].length(); i++)
    {
        iterations++;
        letter = preferred_spots[level][i];
        output = rebuild(output, preferred_spots, current, letter, level + 1, index);

        // OH MY GOD I TRIED TO DO THIS BY APPENDING IT BUT IT NEVER WORKED I DON'T KNOW HOW
        // BUT SETTING OUTPUT TO THE THING WORKS NOW I HAVE SPENT SO LONG ON THIS PROBLEM FINALLY

        // vector<string> vec = rebuild(output, preferred_spots, current, letter, level + 1);
        // output.insert(output.end(), vec.begin(), vec.end());
        // for (size_t x = 0; x < vec.size(); ++x){
        //     cout << " " << vec[x];
        // }
        
    }
    cout << iterations << output.size();
    return output;
}

int main(){

    string input; // the parking arragement to input
    int index; // Index of final preference to find
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


    string temp;

    for (size_t i = 0; i < preferences_input.size(); ++i){
        temp.clear();
        for (size_t u = 0; u < preferences_input[i].length(); u++){
            if (preferences_input[i][u] != ' '){
                letter = 65 + u;
                temp += letter;
            }
        }
        preferred_spots.push_back(temp);
    }

    vector<string> output;
    output = rebuild(output, preferred_spots, "", "", 0, index);

    // for (size_t i = 0; i < output.size(); ++i){
    //     cout << i << " " << output[i] << endl;
    // }

    cout << output[index-1] << endl;
}
