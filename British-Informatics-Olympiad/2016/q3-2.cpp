#include <bits/stdc++.h>
#define ln '\n'
using namespace std;

typedef long long ll;

void part_a() {
    ll upper_limit, start, end;
    cin >> upper_limit >> start >> end;


    // Generates a list of prime numbers, very well known sieve algo for finding all primes.
    vector<bool> is_prime(upper_limit + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= upper_limit; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= upper_limit; j += i)
                is_prime[j] = false;
        }
    }


    // cout << "A" << ln;
    unordered_set<ll> already_checked{};
    {
        queue<ll> to_check{};
        queue<ll> distances{};
        to_check.push(start);
        distances.push(1);

        while (!to_check.empty()) {
            if (already_checked.count(to_check.front())) {
                to_check.pop();
                distances.pop();
                continue;
            }

            already_checked.insert(to_check.front());

            if (to_check.front() == end) {
                cout << "Answer: " << distances.front() << ln;
                break;
            }

            for (ll i = 0; (pow(2, i) + to_check.front()) <= upper_limit; i++) {
                if (is_prime[to_check.front() + pow(2, i)] && !already_checked.count(to_check.front() + pow(2, i))) {
                    to_check.push(to_check.front() + pow(2, i));
                    distances.push(distances.front() + 1);
                }
            }
            for (ll i = 0; (to_check.front() - pow(2, i)) >= 0; i++) {
                if (is_prime[to_check.front() - pow(2, i)] && !already_checked.count(to_check.front() - pow(2, i))) {
                    to_check.push(to_check.front() + -pow(2, i));
                    distances.push(distances.front() + 1);
                }
            }
            // cout << ln << to_check.front() << ln << distances.front() << ln;

            distances.pop();
            to_check.pop();
        }

        // cout << distances.front() << ln;
    }
}

void part_b() {
    ll upper_limit{20}, start{2}, end{19};
    // cin >> upper_limit >> start >> end;

    // Generates a list of prime numbers, very well known sieve algo for finding all primes.
    vector<bool> is_prime(upper_limit + 1, true);
    is_prime[0] = is_prime[1] = false;
    int prime_count = 0;
    for (int i = 2; i <= upper_limit; i++) {
        // cout << i << ln;
        if (is_prime[i]) {
            cout << i << ln;
            prime_count++;

            for (int j = i * i; j <= upper_limit; j += i)
                is_prime[j] = false;
        }
        // if (is_prime[i]) cout << i << ln;
    }

    cout << ln << ln;
    vector<int> dp(prime_count);
    dp[0] = 1;
    for (int i = 0; i < prime_count; i++) {
        for (int j = i + 1; j < prime_count; j++) {
            dp[j] += dp[i] - i;
        }
        cout << dp[i] << " ";
    }
    cout << dp.back() << ln;
}

void part_c() {
    ll n = 250000;
    cout << n * (n - 1) / 2 << ln;
    // ll upper_limit, start, end;
    // cin >> upper_limit >> start >> end;


    // // Generates a list of prime numbers, very well known sieve algo for finding all primes.
    // vector<bool> is_prime(upper_limit + 1, true);
    // is_prime[0] = is_prime[1] = false;
    // for (int i = 2; i * i <= upper_limit; i++) {
    //     if (is_prime[i]) {
    //         for (int j = i * i; j <= upper_limit; j += i)
    //             is_prime[j] = false;
    //     }
    // }


    // cout << "Found all priems." << ln;
    // ll counter = 0;
    // for (int y = 1; y < 250000; y++) {
    //     if (!is_prime[y]) continue;
    //     for (int x = y + 1; x < 250000; x++) {
    //         if (!is_prime[x]) continue;

    //         start = y;
    //         end = x;
    //         unordered_set<ll> already_checked{};
    //         queue<ll> to_check{};
    //         queue<ll> distances{};
    //         to_check.push(start);
    //         distances.push(1);

    //         while (!to_check.empty()) {
    //             if (already_checked.count(to_check.front())) {
    //                 to_check.pop();
    //                 distances.pop();
    //                 continue;
    //             }

    //             already_checked.insert(to_check.front());

    //             if (to_check.front() == end) {
    //                 // cout << "Answer: " << distances.front() << ln;
    //                 counter++;
    //                 cout << start << " " << end << " " << counter << ln;
    //                 break;
    //             }

    //             for (ll i = 0; (pow(2, i) + to_check.front()) <= upper_limit; i++) {
    //                 if (is_prime[to_check.front() + pow(2, i)] && !already_checked.count(to_check.front() + pow(2, i))) {
    //                     to_check.push(to_check.front() + pow(2, i));
    //                     distances.push(distances.front() + 1);
    //                 }
    //             }
    //             for (ll i = 0; (to_check.front() - pow(2, i)) >= 0; i++) {
    //                 if (is_prime[to_check.front() - pow(2, i)] && !already_checked.count(to_check.front() - pow(2, i))) {
    //                     to_check.push(to_check.front() + -pow(2, i));
    //                     distances.push(distances.front() + 1);
    //                 }
    //             }
    //             // cout << ln << to_check.front() << ln << distances.front() << ln;

    //             distances.pop();
    //             to_check.pop();
    //         }

    //         // cout << distances.front() << ln;
    //     }
    // }
}

// Part D: It says that the length of the shortest path will be lesser than n.

int main() {
    // freopen("inputs/q3.txt", "r", stdin);
    // while (true) part_a();  // Part A gets ALL the parts right. :D
    part_b();  // WRONG!!!
    // part_c(); // ALSO WRONGGG!!!
    // Part d: CORRECT!!
}
