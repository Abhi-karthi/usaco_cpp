#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void solve(const vector<int>& current, const vector<int>& target) {
    vector<int> diff(current.size());
    for (int i = 0; i < current.size(); i++) {
        diff.at(i) = target.at(i) - current.at(i);
    }

    vector<vector<int>> islands;
    bool p = false;
    bool n = false;
    vector<int> last_island;
    for (int i : diff) {
        cout << i << " ";
    }
    cout << "\n^ diff \n---------\n";
    for (int i : diff) {
        if (i > 0 && !p) {
            islands.push_back(last_island);
            p = true;
            n = false;
            last_island = {};
        } else if (i < 0 && !n) {
            islands.push_back(last_island);
            p = false;
            n = true;
            last_island = {};
        }
        if (i != 0) last_island.push_back(i);
    }
    islands.push_back(last_island);
    islands.erase(islands.begin());
    for (const auto& i : islands) {
        for (const auto x : i) {
            cout << x << " ";
        }
        cout << "\n";
    }
    cout << "\n^ islands\n---------\n";
    int count = 0;
    for (auto& island : islands) {
        bool equal = false;
        while (!equal) {
            auto min_it = min_element(island.begin(), island.end());
            int lowest = *min_it;
            for (int& i : island) {
                i += lowest;
                if (i != 0) {
                    equal = true;
                }
            }
            count++;
        }
    }
    cout << count << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> current(n);
    vector<int> target(n);
    for (int i = 0; i < n; i++) {
        cin >> current.at(i);
    }
    for (int i = 0; i < n; i++) {
        cin >> target.at(i);
    }

    solve(current, target);

    return 0;
}