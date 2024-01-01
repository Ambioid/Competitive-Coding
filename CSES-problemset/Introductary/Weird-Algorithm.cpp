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
    cout << n << ' ';
    while (n!=1){
        if (n%2==0){
            n/=2;
        }
        else {
            n*=3;
            n+=1;
        }
        cout << n << " ";
    }
}