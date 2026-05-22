#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>

using namespace std;

void solve(const vector<pair<int, int>> &guards) {
    int max_time = -1;
    for (int i = 0; i < guards.size(); i++) {
        bool slots[1000] = { false };
        for (int x = 0; x < i; x++) {
            for (int w = guards[x].first; w < guards[x].second; w++) {
                slots[w] = true;    
            }
        }
        for (int x = i + 1; x < guards.size(); x++) {
            for (int w = guards[x].first; w < guards[x].second; w++) {
                slots[w] = true;
            }
        }
        int count = 0;
        for (int x : slots) {
            if (x) count++;
        }
        max_time = max(max_time, count);
    }

    cout << max_time << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);

    int n;
    cin >> n;
    vector<pair<int, int>> guards(n);
    for (int i = 0; i < n; i++) {
        cin >> guards[i].first >> guards[i].second;
    }

    solve(guards);

    return 0;
}