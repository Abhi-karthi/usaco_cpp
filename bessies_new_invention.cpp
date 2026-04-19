#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Problem {
public:
    int n;
    int k;
    vector<string> grid;
    Problem(int n, int k, vector<string> grid) {
        this->n = n;
        this->k = k;
        this->grid = grid;
    }

    void solve() {
        vector<vector<int>> pascal_grid(n)(n);
        for (int i = 0; i < k; i++) {
            for (int x = 0; x < k; x++) {
                if (grid.at(i).at(x) == '.') {
                    int left_add;
                    if (i < 1) left_add = 0;
                    else left_add = pascal_grid.at(i-1).at(x);
                    int up_add;
                    if (x < 1) up_add = 0;
                    else up_add = pascal_grid.at(i).at(x-1);
                    pascal_
                }
            }
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;


    return 0;
}