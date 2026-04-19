#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, d, s;
    cin >> n >> m >> d >> s;
    vector<vector<int>> cows(d);
    vector<vector<int>> sick_cows(s);
    for (int i = 0; i < d; i++) {
        vector<int> cow(3);
        cin >> cow[0] >> cow[1] >> cow[2];
        cows.at(i) = cow;
    }
    for (int i = 0; i < s; i++) {
        vector<int> cow(2);
        cin >> cow[0] >> cow[1];
        sick_cows.at(i) = cow;
    }

    vector<int> counts(m);
    for (int i = 0; i < m; i++) {
        set<int> curr;

        for (int x = 0; x < d; x++) {
            if (cows[x][1] == i+1) curr.insert(cows[x][0]);
        }
        counts[i] = curr.size();
    }

    int max_count = -1;
    for (int i : counts) {
        if (i > max_count) max_count = i;
    }

    cout << max_count << "\n";

    return 0;
}