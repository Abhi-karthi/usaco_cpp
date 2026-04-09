#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

void solve(int n, int b, std::vector<std::pair<int, int> > points) {
    std::vector<int> maximi;
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            int x_value = points.at(x).first + 1;
            int y_value = points.at(y).second + 1;
            std::vector<int> quadrants(4);
            for (int i = 0; i < points.size(); i++) {
                if (points.at(i).first > x_value && points.at(i).second > y_value) quadrants.at(0)++;
                else if (points.at(i).first > x_value && points.at(i).second < y_value) quadrants.at(1)++;
                else if (points.at(i).first < x_value && points.at(i).second < y_value) quadrants.at(2)++;
                else if (points.at(i).first < x_value && points.at(i).second > y_value) quadrants.at(3)++;
            }
            int current_maximum = -1;
            for (int w = 0; w < 4; w++) {
                if (quadrants.at(w) > current_maximum) {
                    current_maximum = quadrants.at(w);
                }
            }
            maximi.push_back(current_maximum);
        }
    }
    std::vector<int>::iterator max_it = std::min_element(maximi.begin(), maximi.end());
    int min_value = *max_it;
    cout << min_value << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("balancing.in", "r", stdin);
    freopen("balancing.out", "w", stdout);

    int n, b;
    cin >> n >> b;
    std::vector<std::pair<int, int> > points(n);
    for (int i = 0; i < n; i++) {
        cin >> points.at(i).first >> points.at(i).second;
    }

    solve(n, b, points);

    return 0;
}