#include <iostream>
#include <vector>
using namespace std;

void solve(int n, std::vector<int> dance, std::vector<int> id) {
    std::vector<int> curr_dance;
    std::vector<int> prev_dance = id;
    for (int i = 0; i < 3; i++) {
        curr_dance = {};
        for (int x = 0; x < n; x++) {
            curr_dance.push_back(0);
        }

        for (int x = 0; x < n; x++) {
            curr_dance.at(x) = prev_dance.at(dance.at(x));
        }
        prev_dance = curr_dance;
    }
    for (int i = 0; i < n; i++) {
        cout << prev_dance.at(i) << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("shuffle.in", "r", stdin);
    freopen("shuffle.out", "w", stdout);

    int n;
    std::vector<int> dance;
    std::vector<int> id;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int current_dance;
        cin >> current_dance;
        dance.push_back(current_dance-1);
    }
    for (int i = 0; i < n; i++) {
        int curr_id;
        cin >> curr_id;
        id.push_back(curr_id);
    }
    solve(n, dance, id);

    return 0;
}