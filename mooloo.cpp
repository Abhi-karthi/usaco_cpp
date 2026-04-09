#include <iostream>
#include <vector>
using namespace std;

void solve(long long n, long long k, std::vector<long long> days) {
    long long money = k + 1;
    for (int i = 0; i < n - 1; i++) {
        if (days.at(i + 1) - days.at(i) < k + 1) {
            money += days.at(i + 1) - days.at(i);
        } else {
            money += k + 1;
        }
    }
    cout << money << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, k;
    cin >> n >> k;
    std::vector<long long> days(n);
    for (int i = 0; i < n; i++) {
        cin >> days.at(i);
    }

    solve(n, k, days);

    return 0;
}