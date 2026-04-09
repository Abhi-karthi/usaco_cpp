#include <iostream>
#include <utility>
#include <vector>
using namespace std;

void solve(int n, std::vector<std::pair<int, int> > points) {
    int max_area = -1;
    for (int i = 0; i < n; i++) {
        for (int x = 1; x < n; x++) {
            for (int w = 2; w < n; w++) {
                if (i != x && x != w && w != i) {
                    int maximum;
                    if (points.at(i).second == points.at(x).second && points.at(w).first == points.at(x).first) {
                        maximum = (points.at(w).second - points.at(x).second) * (points.at(x).first - points.at(i).first);
                    } else if (points.at(x).second == points.at(i).second && points.at(w).first == points.at(i).first) {
                        maximum = (points.at(w).second - points.at(i).second) * (points.at(i).first - points.at(x).first);
                    } else if (points.at(w).second == points.at(x).second && points.at(i).first == points.at(x).first) {
                    } else if (points.at(w).second == points.at(i).second && points.at(x).first == points.at(i).first) {

                    } else if (points.at(i).second == points.at(w).second && points.at(x).first == points.at(w).first) {

                    } else if (points.at(x).second == points.at(w).second && points.at(i).first == points.at(w).first) {

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

    freopen("triangles.in", "r", stdin);
    freopen("triangles.out", "w", stdout);

    int n;
    cin >> n;
    std::vector<std::pair<int, int> > points;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        points.push_back({x, y});
    }

    solve(n, points);

    return 0;
}