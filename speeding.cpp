#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);

    int n, m;
    cin >> n >> m;
    vector<int> road_limit;
    vector<int> bessie_speed;

    for (int i = 0; i < n; i++) {
        int length, speed_limit;
        cin >> length >> speed_limit;
        for (int x = 0; x < length; x++) {
            road_limit.push_back(speed_limit);
        }
    }
    for (int i = 0; i < m; i++) {
        int length, speed_limit;
        cin >> length >> speed_limit;
        for (int x = 0; x < length; x++) {
            bessie_speed.push_back(speed_limit);
        }
    }

    int max_diff = -1000000000;
    for (int i = 0; i < 100; i++) {
        int diff = bessie_speed[i] - road_limit[i];
        if (diff < 0) diff = 0;
        max_diff = max(max_diff, diff);
    }

    cout << max_diff << "\n";

    return 0;
}