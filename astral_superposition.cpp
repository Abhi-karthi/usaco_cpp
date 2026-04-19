#include <iostream>
#include <vector>
using namespace std;

void solve(int t, std::vector<int> n, std::vector<int> a, std::vector<int> b, std::vector<std::vector<std::vector<int> > > stars) {
    for (int index = 0; index < t; index++) {
        bool continued = false;
        for (int i = 0; i < n.at(index); i++) {
            for (int x = 0; x < n.at(index); x++) {
                cout << i << " " << a.at(index) << "\n";
                if (i - a.at(index) >= 0 && i - a.at(index) < n.at(index) && x - b.at(index) >= 0 && x - b.at(index) < n.at(index)) {
                    if (stars.at(index).at(i - a.at(index)).at(x - b.at(index)) > 0) {
                        continued = true;
                    }
                } else if (i + a.at(index) >= 0 && i + a.at(index) < n.at(index) && x + b.at(index) >= 0 && x + b.at(index) < n.at(index)) {
                    if (stars.at(index).at(i - a.at(index)).at(x - b.at(index)) > 0) {
                        continued = true;
                    }
                } else {
                    continued = true;
                }
            }
            if (continued) break;
        }
        cout << "workign";

        if (!continued) {
            cout << -1 << "\n";
            continue;
        }

        for (int i = 0; i < n.at(index); i++) {
            for (int x = 0; x < n.at(index); x++) {
                if (i - a.at(index) >= 0 && i - a.at(index) < n.at(index) && x - b.at(index) >= 0 && x - b.at(index) < n.at(index) && stars.at(index).at(i).at(x) - 1 < 0) {
                    stars.at(index).at(i).at(x)--;
                    stars.at(index).at(i - a.at(index)).at(x - b.at(index))++;
                } else if (i - a.at(index) < 0 && i - a.at(index) >= n.at(index) && x - b.at(index) < 0 && x - b.at(index) >= n.at(index) && stars.at(index).at(i).at(x) - 1 < 0) {
                    stars.at(index).at(i).at(x)--;
                }
            }
        }

        int sum = 0;
        for (int i = 0; i < n.at(index); i++) {
            for (int x = 0; x < n.at(index); x++) {
                if (stars.at(index).at(i).at(x) > 0) {
                    sum ++;
                }
            }
        }
        cout << sum << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    std::vector<int> n;
    std::vector<int> a;
    std::vector<int> b;
    std::vector<std::vector<std::vector<int> > > stars;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int curr_n;
        int curr_a;
        int curr_b;
        std::vector<std::vector<int> > curr_star;
        cin >> curr_n >> curr_a >> curr_b;
        n.push_back(curr_n);
        a.push_back(curr_a);
        b.push_back(curr_b);
        for (int x = 0; x < curr_n; x++) {
            std::vector<int> curr_star_row;
            string curr_star_row_string;
            cin >> curr_star_row_string;
            for (int l = 0; l < curr_n; l++) {
                char curr_star_value = curr_star_row_string.at(l);
                int curr_star_value_int;
                if (curr_star_value == 'W') {
                    curr_star_value_int = 0;
                } else if (curr_star_value == 'G') {
                    curr_star_value_int = 1;
                } else if (curr_star_value == 'B') {
                    curr_star_value_int = 2;
                }
                curr_star_row.push_back(curr_star_value_int);
            }
            curr_star.push_back(curr_star_row);
        }
        stars.push_back(curr_star);
    }
    solve(t, n, a, b, stars);

    return 0;
}
