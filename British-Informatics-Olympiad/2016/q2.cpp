#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct city {
    ll y;
    ll x;
    ll size = 0;

    bool operator<(city other) const {  // Returns false if more priority, and true if its worth less.
        if (x != other.x) {
            return x < other.x;
        } else {
            return y < other.y;
        }
    }
};

void add_population(set<city>& cities, ll y, ll x) {
    city current{};
    // If requested coordinates exist:
    if (cities.find(city{y, x}) != cities.end()) {
        current = *cities.find(city{y, x});
        cities.erase(city{y, x});
    }

    else {  // If the coordinates requested don't exist
        current = city{y, x};
    }

    current.size += 1;

    if (current.size >= 4) {
        current.size = 0;
        cities.insert(current);
        add_population(cities, current.y, current.x - 1);
        add_population(cities, current.y, current.x + 1);
        add_population(cities, current.y + 1, current.x);
        add_population(cities, current.y - 1, current.x);
    } else {
        cities.insert(current);
    }
}

bool part_a(ll pointer, ll sequence_size, ll simulation_steps, vector<ll> sequence) {
    ll limit = 4;


    pointer--;

    set<city> cities{};
    for (int y = 0; y < 5; y++) {
        for (int x = 0; x < 5; x++) {
            cities.insert(city{y, x});
        }
    }


    for (ll i = 0; i < simulation_steps; i++) {
        // cout << pointer << endl;
        // cout << cities.count(city{pointer / 5, pointer % 5}) << endl;

        add_population(cities, pointer / 5, pointer % 5);
        pointer = (pointer + sequence[i % sequence_size]) % 25;
    }

    bool temp = true;  // Commented code is only for part C below.
    // for (int y = 0; y < 5; y++) {
    //     for (int x = 0; x < 5; x++) {
    //         // cout << (*cities.find(city{y, x})).size << " ";
    //         if (((*cities.find(city{y, x})).size != 1)) {
    //             if ((x == 0) || ((x == 2) && ((y == 0) || (y == 1) || (y == 3)))) {
    //                 temp = false;
    //             }
    //         } else {
    //             if (!((x == 0) || ((x == 2) && ((y == 0) || (y == 1) || (y == 3))))) {
    //                 temp = false;
    //             }
    //         }
    //     }
    //     // cout << endl;
    // }


    for (int y = 0; y < 5; y++) {
        for (int x = 0; x < 5; x++) {
            cout << (*cities.find(city{y, x})).size << " ";
        }
        cout << endl;
    }

    // cout << temp << endl;
    return temp;
}

void part_c() {
    ll sum = 0;
    for (int x = 1; x < 26; x++) {
        for (int y = 0; y < 25; y++) {
            for (int z = 0; z < 25; z++) {
                for (int w = 0; w < 25; w++) {
                    bool temp = part_a(x, 3, 8, vector<ll>{y, z, w});
                    if (temp) {
                        cout << x << " " << y << " " << z << " " << w << "\n";
                    }
                    sum += temp;
                }
            }
        }
    }
    cout << sum << endl;
}

int main() {
    // freopen("inputs/q2.txt", "r", stdin);
    ll pointer, sequence_size, simulation_steps;
    cin >> pointer >> sequence_size >> simulation_steps;

    vector<ll> sequence(sequence_size);
    for (ll& iter : sequence) cin >> iter;
    part_a(pointer, sequence_size, simulation_steps, sequence);
    cout << endl;

    // part_c();
}

// Took me about one and a half hour to do EVERYTHING on this file. Not bad, but I think I need to cut this down even further.
/*

This one was pretty easy actually. Just have a set of

*/