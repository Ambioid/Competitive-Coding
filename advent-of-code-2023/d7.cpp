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

struct deck {
    string cards{};
    long value{};
    multiset<int> pair_counts{};
    char type{};

    string values{"AKQJT98765432"};
    string type_values{"54F321H"};
    // 5, 4, F =Full, 3=Thee of a kind, 2=Two Pair, 1=OnePair, H=High Card

    bool operator<(deck other) const {  // Returns false if more priority, and true if its worth less.

        if (type != other.type) {
            // If left side is worth more, return true
            // cout << type_values.find(type) << endl;
            return (type_values.find(type) < type_values.find(other.type));
        }

        else {
            for (int i = 0; i < cards.size(); i++) {
                if (cards.at(i) == other.cards.at(i)) {
                    continue;
                }
                // If left side is worth more, return true
                else {
                    return (values.find(cards.at(i)) < values.find(other.cards.at(i)));
                }
            }
        }
        return false;
    }
};

int main() {
    freopen("inputs/d7.txt", "r", stdin);

    vector<char> card_values{'A', 'K', 'Q', 'J', 'T', '9', '8', '7', '6', '5', '4', '3', '2'};

    // vector<pair<string, long>> decks{};
    vector<deck> decks{};

    string temp1{};
    long temp2{};
    set<deck> deck_set{};

    while (cin >> temp1 >> temp2) {
        decks.push_back({temp1, temp2});
    }

    // Iterate through every deck-value pair.
    for (int i = 0; i < decks.size(); i++) {
        const string &current_deck = decks.at(i).cards;
        set<char> already_checked_chars{};

        // Count how many pairs
        for (const auto &card : decks.at(i).cards) {
            if (already_checked_chars.count(card) == 0) {
                int temp{count(current_deck.begin(), current_deck.end(), card)};
                decks.at(i).pair_counts.insert(temp);
                already_checked_chars.insert(card);
            }
        }

        auto second_last{decks.at(i).pair_counts.rbegin()};
        second_last--;

        // Give each "deck" object a type based on how many pairs it has
        if (*decks.at(i).pair_counts.rbegin() == 5) {
            decks.at(i).type = '5';  // Five of a kind
        } else if (*decks.at(i).pair_counts.rbegin() == 4) {
            decks.at(i).type = '4';  // Four of a kind
        } else if ((*decks.at(i).pair_counts.rbegin() == 3) && (*second_last == 2)) {
            decks.at(i).type = 'F';  // Full house
        } else if ((*decks.at(i).pair_counts.rbegin() == 3) && (*second_last == 1)) {
            decks.at(i).type = '3';  // Three of a kind
        } else if ((*decks.at(i).pair_counts.rbegin() == 2) && (*second_last == 2)) {
            decks.at(i).type = '2';  // Two Pair
        } else if ((*decks.at(i).pair_counts.rbegin() == 2) && (*second_last == 1)) {
            decks.at(i).type = '1';  // One Pair
        } else if ((*decks.at(i).pair_counts.rbegin() == 1)) {
            decks.at(i).type = 'H';  // High card
        }

        cout << "\nType: " << decks.at(i).type << ". " << decks.at(i).cards << ". ";
        for (const auto &card : decks.at(i).pair_counts) {
            cout << " " << card;
        }

        // Put into a set based on type.
        deck_set.insert(decks.at(i));
        // cout << "\nDeck:" << deck_set.count(decks.at(i)) << '\n';
    }

    sort(decks.begin(), decks.end());

    cout << "\n\nNew Set orderings:\n";

    long winnings{0};
    int i{decks.size()};
    for (const auto &iter : deck_set) {
        cout << iter.cards << " " << iter.value << endl;
        winnings += iter.value * i;
        i--;
    }

    cout << "\n\nWinnings: " << winnings << endl;
}