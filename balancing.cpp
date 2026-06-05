#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("balancing.in", "r", stdin);
    freopen("balancing.out", "w", stdout);

    int n, b;
    cin >> n >> b;

    vector<pair<int, int>> cows(n);
    vector<int> x_values;
    vector<int> y_values;

    for (int i = 0; i < n; i++) {
        cin >> cows[i].first >> cows[i].second;
        x_values.push_back(cows[i].first+1);
        y_values.push_back(cows[i].second+1);
    }

    int least_section = 101;
    for (auto x : x_values) {
        for (auto y : y_values) {
            vector<int> quadrants(4);
            for (auto i : cows) {
                if (i.first > x && i.second > y) {
                    quadrants[0]++;
                } else if (i.first > x && i.second < y) {
                    quadrants[1]++;
                } else if (i.first < x && i.second > y) {
                    quadrants[2]++;
                } else if (i.first < x && i.second < y) {
                    quadrants[3]++;
                }
            }
            least_section = min(least_section, max(max(quadrants[0], quadrants[1]), max(quadrants[2], quadrants[3])));
        }
    }

    cout << least_section << "\n";

    return 0;
}