#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

/* Algorithm Explained: 
Simple Greedy algorithm with 2 loops: First it loops up to the max value (value of the target)
and then it works backwards from there, subtracting the maximum value it can subtract, and then
moving on to the next. This is efficient and runs in O(n) time, and is guaranteed to find shortest
sequence because it'll always target the largest value first. This is a greedy algorithm.
    */

int main(){
    while(true){
    int target{};
    vector<long long> fib{1, 1};
    vector<long long> sum{};
    // cout << fib[fib.size()-1] << endl;
    cout << "Insert Input: " << endl;
    cin >> target;
    while ((fib[fib.size()-1] < target)){
        

        fib.push_back(fib[fib.size()-2] + fib[fib.size()-1]);
        // cout << fib[fib.size()-1] << endl;
        
    }
    
    for (int i{ fib.size()-1 }; i > 0; i--){
        if (fib[i] <= target){
            target -= fib[i];
            sum.push_back(fib[i]);
        }
    }
    cout << "Output:" << endl;
    for(auto& it: sum){
        cout << it << " ";
    }
    cout << endl;

    // // Solution to part B: 832040
    // while ((fib[fib.size()-1] <  1000000)){
    //     cout << fib[fib.size()-1] << endl;
    //     fib.push_back(fib[fib.size()-2] + fib[fib.size()-1]);
    // }
    
}
}

// Did Q1a 24 minutes (36:25 left) (could have easily been faster with more C++ Proficcency)
// Did Q1b shortly after (10 mins I'd say?)
// Spent more time trying to do the last 2 (went until 54m) and did not get them finished.

