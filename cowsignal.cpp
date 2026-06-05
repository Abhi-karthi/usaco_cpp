#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("cowsignal.in", "r", stdin);
    freopen("cowsignal.out", "w", stdout);

    int m, n, k;
    cin >> m >> n >> k;
    vector<string> signal(n);
    for (int i = 0; i < m; i++) {
        cin >> signal[i];
    }

    vector<vector<char>> answer;
    for (int i = 0; i < signal.size(); i++) {
        for (int n1 = 0; n1 < k; n1++) {
            vector<char> row;
            for (int x = 0; x < n; x++) {
                for (int n2 = 0; n2 < k; n2++) {
                    row.push_back(signal[i][x]);
                }
            }
            answer.push_back(row);
        }
    }

    for (auto i : answer) {
        for (auto x : i) {
            cout << x;
        }
        cout << "\n";
    }

    return 0;
}