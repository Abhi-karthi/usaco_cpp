#include <iostream>
#include <utility>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("triangles.in", "r", stdin);
    freopen("triangles.out", "w", stdout);

    int n;
    cin >> n;

    vector<pair<int, int>> points(n);

    for (int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
    }

    int max_area = -1;
    for (pair<int, int> i : points) {
        vector<pair<int, int>> possible_y;
        vector<pair<int, int>> possible_x;

        for (auto x : points) {
            if (!(x.first == i.first && x.second == i.second)) {
                if (x.first == i.first) {
                    possible_y.push_back(x);
                } else if (x.second == i.second) {
                    possible_x.push_back(x);
                }
            }
        }

        for (auto x : possible_x) {
            for (auto y : possible_y) {
                int x_dist = abs(x.first - i.first);
                int y_dist = abs(y.second - i.second);
                int area = x_dist * y_dist;
                if (area > max_area) max_area = area;
            }
        }
    }

    cout << max_area << "\n";

    return 0;
}