#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <unordered_map>
using namespace std;

int find_index(const string& month) {
    const vector<string> months = {"Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig", "Rat"};
    for (int i = 0; i < months.size(); i++) {
        if (months.at(i) == month) {
            return i;
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
   
    unordered_map<string, pair<string, int>> cows = {{"Bessie", {"Ox", 0}}};
   
    int n;
    cin >> n;
    vector<vector<string>> sentences;
    for (int i = 0; i < n; i++) {
        vector<string> sentence(8);
        for (int x = 0; x < 8; x++) {
            cin >> sentence.at(x);
        }
        sentences.push_back(sentence);
    }
   
    bool found = false;
    string prev = "Bessie";

    while (true) {
        for (const auto& i : cows) {
            if (i.first == "Elsie") found = true;
        }
        if (found) break;
        vector<string> sentence;
        for (auto i : sentences) {
            if (i[7] == prev) {
                sentence = i;
                break;
            }
        }


        // for (const auto& i : sentence) {
        //     cout << i << " ";
        // }
        // cout << "\n";
        string year = sentence.at(4);
        int ind = find_index(year);
        int diff;
        if (sentence[3] == "previous") {
            if (ind > find_index(cows[prev].first)) {
                diff = 12 - abs(ind - find_index(cows[prev].first));
            } else {
                diff = find_index(cows[prev].first);
            }
            diff *= -1;
        } else {
            if (ind > find_index(cows[prev].first)) {
                diff = find_index(cows[prev].first);
            } else {
                diff = 12 - abs(ind - find_index(cows[prev].first));
            }
        }

        cows[sentence[0]] = {year, cows[prev].second + diff};
        // cout << diff << "\n";
        prev = sentence[0];
    }
    cout << abs(cows["Elsie"].second) << "\n";
   
    return 0;
}