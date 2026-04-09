#include <iostream>
#include <vector>
using namespace std;

void solve(int k, int n, vector<int> x_values) {
    for (int x : x_values) {
        int distance = 0;
        int speed = 0;
        int time = 0;
        while (distance < k) {
            speed++;
            distance += speed;
            time++;
            if (distance >= k) {
                break;
            }
            if (speed >= x) {
                distance += speed;
                time++;
            }
        }
        cout << time << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k, n;
    cin >> k >> n;

    vector<int> x_vals(n);
    for (int i = 0; i < n; i++) {
        cin >> x_vals.at(i);
    }

    solve(k, n, x_vals);

    return 0;
}