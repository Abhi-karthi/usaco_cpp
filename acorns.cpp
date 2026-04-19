#include <iostream>
#include <vector>
using namespace std;

void solve(int n, int x, std::vector<int> nuts) {
    std::vector<int> amounts;
    for (int i = 0; i < n; i++) {
        for (int w = i + 1; w < n; w++) {
            int higher;
            int lower;
            if (nuts.at(i) <= nuts.at(w)) {
                lower = nuts.at(i);
                higher = nuts.at(w);
            } else {
                lower = nuts.at(w);
                higher = nuts.at(i);
            }
            // cout << i << " " << w << "\n";
            if (abs(lower - higher) > x) continue;
            amounts.push_back(0);
            // cout << lower << " " << higher << "\n";
            for (int v = 0; v < n; v++) {
                if (nuts.at(v) >= lower && nuts.at(v) <= higher) {
                    amounts.at(amounts.size() - 1)++;
                    // cout << "added ";
                } else if (nuts.at(v) < lower) {
                    if (abs(nuts.at(v) - higher) <= x) {
                        amounts.at(amounts.size() - 1)++;
                        lower = nuts.at(v);
                    }
                    // cout << "went down ";
                }
            }
            // cout << "next \n";

            amounts.push_back(0);
            for (int v = 0; v < n; v++) {
                if (nuts.at(v) >= lower && nuts.at(v) <= higher) {
                    amounts.at(amounts.size() - 1)++;
                } else if (nuts.at(v) > higher) {
                    if (abs(nuts.at(v) - lower) <= x) {
                        amounts.at(amounts.size() - 1)++;
                        higher = nuts.at(v);
                    }
                }
            }
        }
    }

    int max = -1;
    for (int i = 0; i < amounts.size(); i++) {
        if (amounts.at(i) > max) max = amounts.at(i);
    }
    cout << max << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    cin >> n >> x;
    std::vector<int> nuts(n);
    for (int i = 0; i < n; i++) {
        cin >> nuts.at(i);
    }

    solve(n, x, nuts);

    return 0;
}