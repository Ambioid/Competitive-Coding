#include <bits/stdc++.h>

using namespace std;
#define ln '\n'
typedef long long ll;

set<multiset<ll>> item_permutations(map<multiset<ll>, set<multiset<ll>>>& memo, const ll& max_item_weight, const ll& parcel_weight, const multiset<ll>& parcel) {
    if (memo.count(parcel)) return memo.at(parcel);

    ll total_weight = 0;
    for (const auto& iter : parcel) total_weight += iter;


    if (total_weight > parcel_weight) {
        // cout << "Incorrect: "<<ln;
        // for (const auto& iter: parcel) cout << iter<<ln;
        // cout <<ln;
        return {};
    } else if (total_weight == parcel_weight) {
        // cout << "Correct: "<<ln;
        // for (const auto& iter: parcel) cout << iter<<ln;
        return set<multiset<ll>>{parcel};
    }


    set<multiset<ll>> temp_parcel_set{};
    for (ll i = 1; i <= max_item_weight; i++) {
        multiset<ll> temp_parcel = parcel;
        temp_parcel.insert(i);
        set<multiset<ll>> temp = item_permutations(memo, max_item_weight, parcel_weight, temp_parcel);
        for (const auto& iter : temp) temp_parcel_set.insert(iter);
        // for (const auto& iter: temp) for (const auto& iter2:iter) cout << iter2<<" ";
        // cout <<ln;
    }

    memo.emplace(parcel, temp_parcel_set);
    return temp_parcel_set;
}  // Took me 2/3 of the alloted time to write this function.

// ll assemble_parcels(auto& memo, const map<ll, ll> &parcel_item_density, ll remain_items, ll remain_parcels, ll permutations){
//     if (remain_items <0) {return 0; cout <<"Return0"<<ln;}
//     if (remain_parcels<0) {return 0; cout <<"Return0"<<ln;}
//     if( remain_items == remain_parcels==0  ) return permutations;
//     // ll permutations =0;
//     cout << "Permutations: "<<permutations<<ln;
//     for(const auto& iter: parcel_item_density){
//         permutations += assemble_parcels(memo, parcel_item_density, remain_items- iter.first, remain_parcels-1, permutations*iter.second);
//     }
//     return permutations;
// }

// Each call of the function asks: How many ways are there to get x items from y parcels?
ll parcel_permutations(map<pair<ll, ll>, ll>& memo, const map<ll, ll>& parcel_item_density, ll item_slots_left, ll remaining_parcels) {
    if (memo.count({item_slots_left, remaining_parcels})) return memo.at({item_slots_left, remaining_parcels});

    if (remaining_parcels == 0 && item_slots_left == 0) return 1;
    if (item_slots_left < 0) return 0;
    if (remaining_parcels < 0) return 0;

    ll permutations = 0;
    for (const auto& iter : parcel_item_density) {
        // If parcel x doesn't have more items than we have space for
        if (iter.first <= item_slots_left) {
            // The amount of permutations will also include all the ways
            permutations += iter.second * parcel_permutations(memo, parcel_item_density, item_slots_left - iter.first, remaining_parcels - 1);
        }
    }

    memo.emplace(pair{item_slots_left, remaining_parcels}, permutations);

    return permutations;
}

void part_a() {
    ll total_parcels, max_item_weight, items_in_all_parcels, parcel_weight;
    cin >> total_parcels >> max_item_weight >> items_in_all_parcels >> parcel_weight;


    map<multiset<ll>, set<multiset<ll>>> memo1{};  // Mapping of
    set<multiset<ll>> parcel_possibilities = item_permutations(memo1, max_item_weight, parcel_weight, {});
    map<ll, ll> parcel_item_density{};  // mapping of items in parcel, to amount of parcels with such items.


    for (const auto& iter1 : parcel_possibilities) {
        if (parcel_item_density.count(iter1.size()))
            parcel_item_density.at(iter1.size())++;
        else
            parcel_item_density.emplace(iter1.size(), 1);

        // for (const auto& iter2 : iter1) {
        //     cout << iter2 << " ";
        // }
        // cout << ln;
    }
    // auto& memo, map<ll,ll>&parcel_item_density, const ll& max_weight, const ll& remaining_items, const vector<ll>& parcels,
    // set<ll> memo;
    // ll possible_permutations = assemble_parcels(memo, parcel_item_density, items_in_all_parcels, total_parcels, 1);

    map<pair<ll, ll>, ll> memo2{};

    cout << "Permutations: " << parcel_permutations(memo2, parcel_item_density, items_in_all_parcels, total_parcels) << ln;
}  // This is correct in all test cases. But on the worst test case its probably 2 seconds or so. Not much I *can* do though.

int main() {
    freopen("inputs/q3.txt", "r", stdin);
    part_a();
    // part_b();
}