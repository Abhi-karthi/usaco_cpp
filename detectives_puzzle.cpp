#include <iostream>
#include <utility>
#include <set>
#include <vector>
using namespace std;

void solve(const int y_val, const int x_val, const vector<vector<char>>& list) {
    vector<pair<int, int>> clues;
    for (int i = 0; i < list.size(); i++) {
        for (int x = 0; x < list.at(i).size(); x++) {
            if (x <= x_val - 3) {
                if (list.at(i).at(x) == '.' && list.at(i).at(x + 1) == '.' && list.at(i).at(x + 2) == '.') {
                    if (x > 0) {
                        if (list.at(i).at(x - 1) == '#') {
                            clues.emplace_back(i + 1, x + 1);
                            continue;
                        }
                    } else {
                        clues.emplace_back(i + 1, x + 1);
                        continue;
                    }
                }
            }
            if (i <= y_val - 3) {
                if (list.at(i).at(x) == '.' && list.at(i + 1).at(x) == '.' && list.at(i + 2).at(x) == '.') {
                    if (i > 0) {
                        if (list.at(i - 1).at(x) == '#') clues.emplace_back(i + 1, x + 1);
                    } else {
                        clues.emplace_back(i + 1, x + 1);
                    }
                }
            }
        }
    }

    cout << clues.size() << "\n";
    for (const auto i : clues) {
        cout << i.first << " " << i.second << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int y, x;
    cin >> y >> x;
    vector<vector<char>> list;
    for (int i = 0; i < y; i++) {
        vector<char> row;
        for (int w = 0; w < x; w++) {
            char curr;
            cin >> curr;
            row.push_back(curr);
        }
        list.push_back(row);
    }

    // for (const auto& i_ : list) {
    //     for (const auto x_ : i_) {
    //         cout << x_ << " ";
    //     }
    //     cout << "\n";
    // }

    solve(y, x, list);

    return 0;
}
