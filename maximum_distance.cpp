#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int calc(const  pair<int, int>& point1, const pair<int, int>& point2) {
    return (point1.first - point2.first)*(point1.first - point2.first) + (point1.second- point2.second)*(point1.second - point2.second);
}

void solve(const vector<pair<int, int>>& points) {
    int maximum_distance = -1;
    for (int i = 0; i < points.size(); i++) {
        for (int x = i + 1; x < points.size(); x++) {
            const int distance = calc(points[i], points[x]);
            if (distance > maximum_distance) {
                maximum_distance = distance;
            }
        }
    }

    cout << maximum_distance << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<pair<int, int>> points(n);

    for (int i = 0; i < n; i++) {
        cin >> points[i].first;
    }
    for (int i = 0; i < n; i++) {
        cin >> points[i].second;
    }

    solve(points);

    return 0;
}