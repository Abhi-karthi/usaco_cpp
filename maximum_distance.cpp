#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void solve(int n, std::vector<int> x_values, std::vector<int> y_values) {
    long long max_distance = -1;
    for (int i = 0; i < n; i++) {
        for (int x = 0; x < n; x++) {
            if (x == i) {
                continue;
            }
            if (static_cast<long long>(std::pow(y_values.at(x) - y_values.at(i), 2) + std::pow(x_values.at(x) - x_values.at(i), 2)) > max_distance) {
                max_distance = static_cast<long long>(std::pow((y_values.at(x) - y_values.at(i)), 2) + std::pow(x_values.at(x) - x_values.at(i), 2));
            }
        }
    }
    cout << max_distance << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    std::vector<int> x_values;
    std::vector<int> y_values;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int curr_x_val;
        cin >> curr_x_val;
        x_values.push_back(curr_x_val);
    }
    for (int i = 0; i < n; i++) {
        int curr_y_val;
        cin >> curr_y_val;
        y_values.push_back(curr_y_val);
    }

    solve(n, x_values, y_values);

    return 0;
}