#include <iostream>
#include <vector>
#include <utility>
using namespace std;

void solve(const vector<pair<char, int>>& list) {
    vector<pair<int, int>> positions;
    pair<int, int> curr_position = {0, 0};
    positions.push_back(curr_position);
    for (const auto i : list) {
        for (int x = 0 ; x < i.second; x++) {
            if (i.first == 'N') {
                curr_position.second += 1;
            } else if (i.first == 'S') {
                curr_position.second -= 1;
            } else if (i.first == 'W') {
                curr_position.first -= 1;
            } else if (i.first == 'E') {
                curr_position.first += 1;
            }
            positions.push_back(curr_position);
        }
    }

    int min_distance = -1;
    for (int i = 0; i < positions.size(); i++) {
        for (int x = i + 1; x < positions.size(); x++) {
            if (positions.at(i).first == positions.at(x).first && positions.at(i).second == positions.at(x).second) {
                if (x - i < min_distance || min_distance == -1) min_distance = x - i;
            }
        }
    }

    cout << min_distance << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<pair<char, int>> list(n);
    for (int i = 0; i < n; i++) {
        cin >> list.at(i).first >> list.at(i).second;
    }

    solve(list);

    return 0;
}