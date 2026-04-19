#include <iostream>
#include <utility>
#include <vector>
using namespace std;

void solve(int n, vector<pair<int, int>> cows) {
    int minimum_maximum = 101;
    for (pair<int, int> cow1 : cows) {
        for (pair<int, int> cow2 : cows) {
            int x_quad = cow1.first + 1;
            int y_quad = cow2.second + 1;
            int quad1 = 0;
            int quad2 = 0;
            int quad3 = 0;
            int quad4 = 0;
            for (pair<int, int> cow3 : cows) {
                if (cow3.first > x_quad && cow3.second > y_quad) quad1++;
                else if (cow3.first < x_quad && cow3.second > y_quad) quad2++;
                else if (cow3.first > x_quad && cow3.second < y_quad) quad3++;
                else if (cow3.first < x_quad && cow3.second < y_quad) quad4++;
            }
            if (quad2 > quad1) quad1 = quad2;
            if (quad3 > quad1) quad1 = quad3;
            if (quad4 > quad1) quad1 = quad4;
            if (quad1 < minimum_maximum) minimum_maximum = quad1;
        }
    }

    cout << minimum_maximum << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, b;
    cin >> n >> b;
    vector<pair<int, int>> cows(n);
    for (int i = 0; i < n; i++) {
        pair<int, int> curr_pair;
        cin >> curr_pair.first >> curr_pair.second;
        cows.at(i) = curr_pair;
    }

    solve(n, cows);

    return 0;
}