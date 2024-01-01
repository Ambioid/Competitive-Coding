#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    freopen("input.txt", "r", stdin);

    int total_books, max_total_price;
    cin >> total_books >> max_total_price;

    vector<int> books(total_books);
    for (int& x : books) cin >> x;

    vector<int> pages(total_books);
    for (int& x : pages) cin >> x;
}