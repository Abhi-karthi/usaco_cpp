#include <iostream>
#include <string>
#include <set>
using namespace std;

void solve(int n, string values) {
    std::set<int> answers;
    char begin = 'n';
    char end = 'n';
    bool last_f = false;
    int f_size = 0;
    for (int i = 0; i < n; i++) {
        if (values.at(i) != 'F') {
            if (last_f) {
                end = values.at(i);
                last_f = false;
                std::vector<int> new_additions;
                for (const auto& i : answers) {
                    if (end == begin && f_size % 2 == 1) {
                        for (int x = 0; x <= f_size + 1; x += 2) {
                            new_additions.push_back(x);
                        }
                    } else if (end != begin && f_size % 2 == 1) {
                        for (int x = 1; x <= f_size; x += 2) {
                            new_additions.push_back(x);
                        }
                    }
                }
                f_size = 0;
            } else {
                begin = values.at(i);
            }
        } else {
            last_f = true;
            f_size++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    string values;
    cin >> n;
    cin >> values;

    solve(n, values);

    return 0;
}