#include <iostream>
#include <vector>
using namespace std;

void solve(int n, std::vector<int> cows) {
    std::vector<std::vector<int> > mapping;
    int last_f_index = -1;
    for (int i = 0; i < n; i++) {
        int level; // level 3 is forward, level 2 is backward, level 1 is correct
        if (cows.at(i) > i) {
            level = 3;
            last_f_index = i;
        } else if (cows.at(i) < i) {
            level = 2;
        } else {
            level = 1;
        }
        mapping.push_back({cows.at(i), level});
    }

    for (int i = 0; i < n; i++) {
        int index_to_insert = -1;
        int most_correct_value = -1;
        for (int x = 1; x < n; x++) {
            if (mapping.at(x).at(1) != 3 && x > last_f_index && mapping.at(x).at(0) > mapping.at(i).at(0)) {
                most_correct_value mapping.at(x).at(0) - mapping.at(i).at(0) - 1 == 1
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("sleepy.in", "r", stdin);
    freopen("sleepy.out", "w", stdout);

    int n;
    std::vector<int> cows;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int curr_cow;
        cin >> curr_cow;
        cows.push_back(curr_cow-1);
    }
    solve(n, cows);

    return 0;
}