#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;


int main() {
while(true){
    double debt{100};
    double total_repaid{0};


    double interest{10};
    double repayment{50};
    cout << "Input: \n";
    cin >> interest >> repayment;
    interest /=100;
    repayment /=100;

    int count {0};

    while (debt > 0){
        debt += debt*interest;
        // cout << "Debt: " << debt << endl;
        total_repaid += max(repayment*debt, 50.0);

        debt -= max(repayment*debt, 50.0);
        // cout << "Debt: " << debt << endl;
        count +=1;
    }
    total_repaid += debt;

    cout << "Total repaid: " << total_repaid << endl;
    // cout << "Count: "<< count << endl;
}}

// Took me literally 15 minutes to write this. Should have been 10.
