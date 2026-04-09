#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

void solve(int n, std::vector<int> petals) {
    std::vector<int> averages;
    for (int i = 0; i < n; i++) {
        for (int x = i + 1; x < n; x++) {
            double val = (petals.at(i) + petals.at(x));
            val = val / 2;
            // cout << val << "\n";
            if (std::fmod(val, 1.0) == 0) {
                averages.push_back(static_cast<int>(val));
            }
        }
    }

    // for (int i = 0; i < averages.size(); i++) {
    //     cout << averages.at(i) << " ";
    // }
    // cout << "\n";

    int count = 0;
    for (int i = 0; i < petals.size(); i++) {
        for (int x = i + 1; x < n; x++) {
            for (int w = 0; w < averages.size(); w++) {
                if (petals.at(i) == averages.at(w) || petals.at(x) == averages.at(w)) {
                    count++;
                    break;
                }
            }
        }
    }

    cout << count << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    std::vector<int> petals;
    for (int i = 0; i < n; i++) {
        int curr;
        cin >> curr;
        petals.push_back(curr);
    }

    solve(n, petals);

    return 0;
}