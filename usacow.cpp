#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k, n;
    cin >> k >> n;

    vector<vector<int> > rankings;
    for (int i = 0; i < k; i++) {
        vector<int> rank;
        for (int x = 0; x < n; x++) {
            int curr;
            cin >> curr;
            rank.push_back(curr);
        }
        rankings.push_back(rank);
    }

    int count = 0;
    for (int cow1 = 1; cow1 < n+1; cow1++) {
        for (int cow2 = cow1 + 1; cow2 < n+1; cow2++) {
            pair<int, int> curr_rank;
            for (auto i : rankings) {
                for (int x : i) {
                    if (x == cow1) {
                        curr_rank.first++;
                        break;
                    }
                    if (x == cow2) {
                        curr_rank.second++;
                        break;
                    }
                }
            }

            if (curr_rank.first == 0 || curr_rank.second == 0) {
                count++;
                // cout << cow1 << ", " << cow2 << "\n";
            }
        }
    }

    cout << count << "\n";

    return 0;
}