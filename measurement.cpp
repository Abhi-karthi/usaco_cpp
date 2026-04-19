#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(const vector<int>& a, const vector<int>& b) {
    return a[0] < b[0];
}

void solve(int n, std::vector<std::vector<int> > inputs) {
    sort(inputs.begin(), inputs.end(), compare);
    // for (int i = 0; i < n; i++) {
    //     cout << inputs.at(i).at(0) << "\n";
    // }
    std::vector<int> lead = {1, 1, 1};
    std::vector<int> prev_lead = {1, 1, 1};
    std::vector<int> count = {7, 7, 7};
    int solution = 0;
    for (int i = 0; i < n; i++) {
        count.at(inputs.at(i).at(1)) += inputs.at(i).at(2);
        // for (int x = 0; x < count.size(); x++) {
        //     cout << count.at(x) << " ";
        // }
        for (int x = 0; x < 3; x++) {
            bool greatest = true;
            for (int v = 0; v < 3; v++) {
                if (v!=x) {
                    if (count.at(x) < count.at(v)) {
                        greatest = false;
                        break;
                    }
                }
            }
            if (greatest) {
                lead.at(x) = 1;
            } else {
                lead.at(x) = 0;
            }
        }
        if (prev_lead != lead) {
            solution ++;
        }
        prev_lead = lead;
    }
    cout << solution << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("measurement.in", "r", stdin);
    freopen("measurement.out", "w", stdout);

    int n;
    std::vector<std::vector<int> > inputs;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int day;
        string cow;
        int cow_number = -1;
        int change;
        cin >> day >> cow >> change;
        if (cow == "Mildred") {
            cow_number = 0;
        } else if (cow == "Elsie") {
            cow_number = 1;
        } else if (cow == "Bessie") {
            cow_number = 2;
        }
        inputs.push_back({day, cow_number, change});
    }

    solve(n, inputs);

    return 0;
}