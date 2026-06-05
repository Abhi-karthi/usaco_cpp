#include <iostream>
#include <vector>
#include <string>
#include <utility>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("circlecross.in", "r", stdin);
    freopen("circlecross.out", "w", stdout);

    string m_string;
    cin >> m_string;

    vector<pair<int, int>> cows(26, make_pair(-1, -1));
    for (int i = 0; i < 52; i++) {
        const char curr = m_string[i];
        const int curr_value = curr-'A';
        if (cows[curr_value].first == -1) {
            cows[curr_value].first = i;
        } else {
            cows[curr_value].second = i;
        }
    }

    int total_count = 0;
    for (int i = 0; i < 26; i++) {
        for (int x = i + 1; x < 26; x++) {
            int first_count = 0;
            int second_count = 0;

            auto first_pair = cows[i];
            auto second_pair = cows[x];

            if (second_pair.first <= first_pair.first && first_pair.first <= second_pair.second) {
                first_count++;
            }
            if (second_pair.first <= first_pair.second && first_pair.second <= second_pair.second) {
                first_count++;
            }
            if (first_pair.first <= second_pair.first && second_pair.first <= first_pair.second) {
                second_count++;
            }
            if (first_pair.first <= second_pair.second && second_pair.second <= first_pair.second) {
                second_count++;
            }

            if (first_count == 1 && second_count == 1) {
                total_count++;
            }
        }
    }

    cout << total_count << "\n";

    return 0;
}