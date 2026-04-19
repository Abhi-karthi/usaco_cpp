#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
using namespace std;

bool parallel_to_x(const pair<int, int>& first, const pair<int, int>& second) {
    if (first.second == second.second) return true;
    return false;
}

bool parallel_to_y(const pair<int, int>& first, const pair<int, int>& second) {
    if (first.first == second.first) return true;
    return false;
}

int find_area(const pair<int, int>& point1, const pair<int, int>& point2, const pair<int, int>& point3) {
    double side_length1 = pow(pow(point2.second - point1.second, 2.0) + pow(point2.first - point1.first, 2.0), 0.5);
    double side_length2 = pow(pow(point3.second - point2.second, 2.0) + pow(point3.first - point2.first, 2.0), 0.5);
    double side_length3 = pow(pow(point3.second - point1.second, 2.0) + pow(point3.first - point1.first, 2.0), 0.5);
    if (side_length1 > side_length2 && side_length1 > side_length3) {
        return side_length2 * side_length3;
    }
    if (side_length2 > side_length1 && side_length2 > side_length3) {
        return side_length1 * side_length3;
    }
    return side_length1 * side_length2;
}

void solve(int n, vector<pair<int, int>> points) {
    int max_area = -1;
    for (int i = 0; i < n; i++) {
        for (int x = i + 1; x < n; x++) {
            for (int v = x + 1; v < n; v++) {
                if ((parallel_to_x(points.at(x), points.at(v)) || parallel_to_x(points.at(x), points.at(i)) || parallel_to_x(points.at(i), points.at(v))) && (parallel_to_y(points.at(x), points.at(v)) || parallel_to_y(points.at(x), points.at(i)) || parallel_to_y(points.at(i), points.at(v)))) {
                    int area = find_area(points.at(i), points.at(x), points.at(v));
                    if (area > max_area) {
                        max_area = area;
                    }
                }
            }
        }
    }
    cout << max_area << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; i++) {
        pair<int, int> curr_pair;
        cin >> curr_pair.first >> curr_pair.second;
        points.at(i) = curr_pair;
    }
    
    solve(n, points);
    
    return 0;
}