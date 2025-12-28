#include <iostream>
#include <vector>
using namespace std;

void solve(int n, std::vector<long long> cow_heights) {
    int bessie_index = 0;
    for (int i = 1; i < n; i++) {
        cout << cow_heights.at(i) << " " << cow_heights.at(i - 1) << "\n";
        if (cow_heights.at(i) < cow_heights.at(i - 1)) {
            bessie_index = i;
            break;
        }
    }
    cout << bessie_index << "\n";
    std::vector<long long> digits_crossed;
    int duplicate_digits = 0;
    int swaps = 0;
    while (true) {
        if (bessie_index == 0) {
            if (cow_heights.at(bessie_index) <= cow_heights.at(1)) {
                cout << swaps << "\n";
                break;
            }
            digits_crossed.push_back(cow_heights[bessie_index + 1]);
            std::swap(cow_heights[bessie_index], cow_heights[bessie_index + 1]);
            bessie_index ++;
        } else if (bessie_index == cow_heights.size() - 1) {
            if (cow_heights.at(bessie_index) >= cow_heights.at(bessie_index - 1)) { break; }
            digits_crossed.push_back(cow_heights[bessie_index - 1]);
            std::swap(cow_heights[bessie_index], cow_heights[bessie_index - 1]);
            bessie_index --;
        } else {
            if (cow_heights.at(bessie_index) >= cow_heights.at(bessie_index - 1) && cow_heights.at(bessie_index) <= cow_heights.at(bessie_index + 1)) { break; }
            if (cow_heights.at(bessie_index) < cow_heights.at(bessie_index - 1)) {
                digits_crossed.push_back(cow_heights[bessie_index - 1]);
                std::swap(cow_heights[bessie_index], cow_heights[bessie_index - 1]);
            } else {
                digits_crossed.push_back(cow_heights[bessie_index + 1]);
                std::swap(cow_heights[bessie_index], cow_heights[bessie_index + 1]);
            }
        }
        swaps ++;
    }
    for (int i = 0; i < digits_crossed.size(); i++) {
        for (int x = 0; x < digits_crossed.size(); x++) {
            if (x!=i && digits_crossed.at(x) == digits_crossed.at(i)) {
                duplicate_digits ++;
            }
        }
    }
    cout << duplicate_digits << "\n";
    duplicate_digits /= 2;
    swaps -= duplicate_digits - 1;
    cout << swaps << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("outofplace.in", "r", stdin);
    freopen("outofplace.out", "w", stdout);

    int n;
    cin >> n;
    std::vector<long long> cow_heights;
    for (int i = 0; i < n; i++) {
        int curr_cow_height;
        cin >> curr_cow_height;
        cow_heights.push_back(curr_cow_height);
    }
    // for (int i = 0; i < cow_heights.size(); i++) {
    //     cout << cow_heights.at(i) << " ";
    // }
    // cout << "\n";
    solve(n, cow_heights);

    return 0;
}