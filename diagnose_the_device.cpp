#include <iostream>
#include <utility>
#include <vector>
using namespace std;

void solve(int n, vector<pair<string, vector<string>>> lines) {
    int max_count = 0;
    for (int i = 0; i < n; i++) {
        for (int x = i + 1; x < n; x++) {
            vector<string>& first_traits = lines.at(i).second;
            vector<string> second_traits = lines.at(x).second;
            int curr_count = 0;
            for (int w = 0; w < first_traits.size(); w++) {
                for (int v = 0; v < second_traits.size(); v++) {
                    if (first_traits.at(w) == second_traits.at(v)) {
                        curr_count++;
                    }
                }
            }
            if (curr_count > max_count) {
                max_count = curr_count;
            }
        }
    }

    cout << max_count + 1 << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // cycle through every pair
    // make list of amount of common traits
    // answer = max(common_traits) + 1

    int n;
    cin >> n;
    vector<pair<string, vector<string>>> lines(n);
    for (int i = 0; i < n; i++) {
        pair<string, vector<string>> curr_pair;
        cin >> curr_pair.first;
        int length;
        cin >> length;
        vector<string> curr_vector(length);
        for (int x = 0; x < length; x++) {
            cin >> curr_vector.at(x);
        }
        curr_pair.second = curr_vector;
        lines.at(i) = curr_pair;
    }
    solve(n, lines);

    return 0;
}