#include <iostream>
#include <vector>
using namespace std;

void solve(int n, int m, int k, std::vector<int> cows_in_order, std::vector<int> ci, std::vector<int> pi) {
    std::vector<int> spots_filled;
    for (int v = 0; v < ci.size(); v++) {
        if (v == 0)
        spots_filled.push_back(pi.at(v));
        bool here = false;
        int index = 0;
        for (int x = 0; x < cows_in_order.size(); x++) {
            if (cows_in_order.at(x) == ci.at(v)) {
                here = true;
                index = x;
                break;
            }
        }
        if (here) {
            int c1 = 1;
            for (int i = index - 1; i >= 0; i--) {
                spots_filled.push_back(pi.at(v) - c1);
                c1++;
            }
        }
    }
    for (int i = 1; i < n; i++) {
        bool cn = false;
        for (int x = 0; x < spots_filled.size(); x++) {
            if (i == spots_filled.at(x)) {
                cn = true;
            }
        }
        if (cn) { continue; }
        cout << i << "\n";
        return;
    }
    cout << n << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("milkorder.in", "r", stdin);
    freopen("milkorder.out", "w", stdout);

    int n, m, k;
    std::vector<int> cows_in_order;
    std::vector<int> ci;
    std::vector<int> pi;
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int curr_cow_in_order;
        cin >> curr_cow_in_order;
        cows_in_order.push_back(curr_cow_in_order);
    }
    for (int i = 0; i < k; i++) {
        int curr_ci;
        int curr_pi;
        cin >> curr_ci >> curr_pi;
        ci.push_back(curr_ci);
        pi.push_back(curr_pi);
    }

    solve(n, m, k, cows_in_order, ci, pi);

    return 0;
}