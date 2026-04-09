#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    std::vector<std::vector<int> > array_2d;
    for (int i = 0; i < n; i++) {
        std::vector<int> curr_row;
        for (int x = 0; x < m; x++) {
            int curr_int;
            cin >> curr_int;
            curr_row.push_back(curr_int);
        }
        array_2d.push_back(curr_row);
    }
    int k;
    cin >> k;

    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int x = 0; x < m; x++) {
            int sum = 0;
            if (x - 1 >= 0) {
                sum += array_2d.at(i).at(x - 1);
            }
            if (x + 1 < m) {
                sum += array_2d.at(i).at(x + 1);
            }
            if (sum == k) {
                count ++;
            }
        }
    }
    cout << count << "\n";
    return 0;
}