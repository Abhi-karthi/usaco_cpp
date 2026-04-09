#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> routes(m);
    for (int i = 0; i < m; i++) {
        cin >> routes.at(i).first >> routes.at(i).second;
    }

    vector<pair<vector<int>, pair<int, int>>> possibilities; // first part of pair is visited cities, second is last route
    for (pair<int, int> i : routes) {
        if (i.first == 1) {
            possibilities.push_back({{i.first, i.second}, {i.first, i.second}});
        }
    }

    // for (pair<vector<int>, pair<int, int>> possibility : )

    bool going = true;
    while (going) {
        going = false;
        vector<pair<vector<int>, pair<int, int>>> new_possibilities;
        for (int i = 0; i < possibilities.size(); i++) {
            for (pair<int, int> x : routes) {
                if (x.first != possibilities.at(i).second.second) {
                    continue;
                }
                bool continue_ = false;
                for (int w = 0; w < possibilities.at(i).first.size(); w++) {
                    if (x.second == possibilities.at(i).first.at(w)) continue_ = true;
                }
                if (continue_) continue;

                pair<vector<int>, pair<int, int>> new_possibility = possibilities.at(i);
                new_possibility.first.push_back(x.second);
                new_possibility.second = {x.first, x.second};

                new_possibilities.emplace_back(new_possibility);

                going = true;
            }
        }
        possibilities = new_possibilities;
    }

    int count = 0;
    for (int i = 0; i < possibilities.size(); i++) {
        cout << possibilities.at(i).first.size() << "\n";
        if (possibilities.at(i).first.size() == 4) count++;
    }

    cout << count << "\n";

    return 0;
}