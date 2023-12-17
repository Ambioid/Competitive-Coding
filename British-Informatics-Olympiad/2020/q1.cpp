#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

string make_numeral(int number)
{
    unordered_map<string, int> numerals = {{"I", 1}, {"IV", 4}, {"V", 5}, {"IX", 9}, {"X", 10}, {"XL", 40}, {"L", 50}, {"XC", 90}, {"C", 100}, {"CD", 400}, {"D", 500}, {"CM", 900}, {"M", 1000}};
    string output;
    while (number)
    {
        //     for(int i = 0; i < numerals.length(); i++){
        //         if (number <= numerals[i])
        //     }
        for (auto &it : numerals)
        {
            if (it.second <= number)
            {
                number -= it.second;
                output += it.first;
            }
        }
    }
    return output;
}

int main()
{   
    string input = "MMXX";
    int repeats = 3;
    string output;
    cin >> input >> repeats;

    for (int u = 0; u < repeats; u++){
        output = "";
        char current = input[0];
        int count = 1;

        for (int i = 1; i < input.length(); i++){

            if (current == input[i]){
                count += 1;
            }
            else{

                output += make_numeral(count);
                output += current;
                count = 1;
                current = input[i];
            }
        }
        output += make_numeral(count);
        output += current;
        input = output;

        // cout << output << endl;
    }

    int I_count = 0;
    int V_count = 0;

    for (int i = 0; i < output.length(); i++){
        if (output[i] == 'I'){
            I_count += 1;
        }
        if (output[i] == 'V'){
            V_count += 1;
        }
    }
    cout << I_count << " " << V_count << endl << endl;
}
