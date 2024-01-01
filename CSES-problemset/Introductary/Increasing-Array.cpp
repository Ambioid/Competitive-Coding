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
    long n{};
    cin >> n;
    
    long input{};
    long sum{0};

    long prev_num{};
    cin >> prev_num;

    for (int i=1;i<n;i++){
        cin >> input;
        if (prev_num>input){
            sum += prev_num-input;
        }
        prev_num=prev_num;
    }
    
    cout << sum;
}