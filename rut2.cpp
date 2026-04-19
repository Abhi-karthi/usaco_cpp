#include <iostream>
#include <vector>
using namespace std;

void solve(int n, std::vector<std::vector<int> > values) {
    std::vector<std::vector<int> > covered;

    for (int i = 0; i < 200; i++) {
        for (int x = 0; x < n; x++) {
            if (values.at(x).at(3) == 1) {
                covered.push_back({values.at(x).at(1), values.at(x).at(2)});
            }
        }

        for (int x = 0; x < n; x++) {
            if (values.at(x).at(3) != 1) {
                continue;
            }

            if (values.at(x).at(0) == 0) {
                values.at(x).at(2)++;
            } else if (values.at(x).at(0) == 1) {
                values.at(x).at(1)++;
            } else if (values.at(x).at(0) == 2) {
                values.at(x).at(2)--;
            } else if (values.at(x).at(0) == 3) {
                values.at(x).at(1)--;
            }

            for (int w = 0; w < covered.size(); w++) {
                if (covered.at(w).at(0) == values.at(x).at(1) &&
                    covered.at(w).at(1) == values.at(x).at(2)) {

                    values.at(x).at(4) = i + 1;
                    values.at(x).at(3) = -1;
                    break;
                }
            }
        }
    }

    for (int i = 0; i < values.size(); i++) {
        if (values.at(i).at(4) == -1) {
            cout << "Infinity" << "\n";
        } else {
            cout << values.at(i).at(4) << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    std::vector<std::vector<int> > values(n);
    for (int i = 0; i < n; i++) {
        char dir;
        cin >> dir;
        int d;
        if (dir == 'N') d = 0;
        else if (dir == 'E') d = 1;
        else if (dir == 'S') d = 2;
        else d = 3;

        int x, y;
        cin >> x >> y;
        values.at(i) = {d, x, y, 1, -1};
    }

    solve(n, values);

    return 0;
}