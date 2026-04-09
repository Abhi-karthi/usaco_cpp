#include <iostream>
using namespace std;

void solve(int x, int y, int m) {
    int max_size = 0;
    int divisibility = m/y; // 77/25=3
    for (int i = 0; i < divisibility; i++) {
        int remaining = m - (i*y);
        // cout << "remaining: " << remaining << "\n";
        int div2 = remaining/x;
        remaining -= div2 * x;
        if (m-remaining > max_size) {
            max_size = m-remaining;
        }
    }
    cout << max_size << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);

    int x, y, m;
    cin >> x >> y >> m;

    solve(x, y, m);

    return 0;
}