#include <iostream>
#include <vector>
#include <utility>
using namespace std;

vector<pair<int, int>> adjacent_points(const pair<int, int>& point) {
    vector<pair<int, int>> points;;
    if (point.first == 0) {
        points.emplace_back(point.first+1, point.second);
    } else if (point.first == 1000) {
        points.emplace_back(point.first-1, point.second);
    } else {
        points.emplace_back(point.first+1, point.second);
        points.emplace_back(point.first-1, point.second);
    }

    if (point.second == 0) {
        points.emplace_back(point.first, point.second + 1);
    } else if (point.second == 1000) {
        points.emplace_back(point.first, point.second - 1);
    } else {
        points.emplace_back(point.first, point.second + 1);
        points.emplace_back(point.first, point.second - 1);
    }

    return points;
}

int check_around(int grid[1001][1001], const pair<int, int>& point) {
    int count = 0;
    if (grid[point.first][point.second] == 0) return 0;
    for (const auto i : adjacent_points(point)) {
        if (grid[i.first][i.second] == 1) count++;
    }

    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
    }

    int count = 0;
    int grid[1001][1001] = {0};
    for (auto i : points) {
        int adj_count = 0;
        for (const auto& x : adjacent_points(i)) {
            if (check_around(grid, x) == 3) adj_count++;
        }

        int new_count = 0;
        grid[i.first][i.second]++;
        for (auto x : adjacent_points(i)) {
            if (check_around(grid, x) == 3) new_count++;
        }
        if (check_around(grid, i) == 3) new_count++;

        const int add_count = new_count - adj_count;
        count += add_count;
        cout << count << "\n";
    }

    return 0;
}
