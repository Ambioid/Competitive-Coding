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
    // std::set indices;
    set<int> numbers{};
    for (int i = 1; i <= n; ++i)
    {
        numbers.insert(i);
    }

    long input{};
    for (int i = 0; i < n-1; ++i){
        cin >> input;
        numbers.erase(input);
    }
    cout << *numbers.begin();


}