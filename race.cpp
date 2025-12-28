#include <iostream>
#include <vector>
using namespace std;

void solve(int k, int n, std::vector<int> &x) {
    if (k == 0) {
        for (int i = 0; i < n; i++) {cout << 0 << "\n";}
    }

    for (int i = 0; i < x.size(); i++) { // curr_x = 1 // k = 10
        int curr_x = x.at(i);
        int prev_speed = 1;
        int curr_distance = 1;
        int time = 1;
        while (curr_distance < k) { // t = 2; ps = 2; curr_distance = 3
            if (((k - curr_distance)/prev_speed)> prev_speed-curr_x+1) { // 6 meters left > sl = 1 > prev speed is 3 |  if speed < distance + speed_limit
                curr_distance += prev_speed + 1;
                prev_speed ++;
            } else if (((k - curr_distance)/prev_speed)< prev_speed-curr_x+1) {
                curr_distance += prev_speed - 1;
                prev_speed --;
            } else {
                curr_distance += prev_speed;
            }
            time ++;
            // cout << curr_distance << " " << prev_speed << "\n";
        }
        cout << time << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("race.in", "r", stdin);
    freopen("race.out", "w", stdout);
    // cout << "67";
    // return 0;
    int k, n;
    cin >> k >> n;
    std::vector<int> x;
    for (int i = 0; i < n; i++) {
        int curr_x;
        cin >> curr_x;
        x.push_back(curr_x);
    }
    solve(k, n, x);

    return 0;
}