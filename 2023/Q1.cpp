#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

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

