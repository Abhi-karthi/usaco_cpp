#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int the_thing(int length, int nights) {
    std::vector<int> ones(1, length);
    for (int i = 0; i < length; i++) {
        if (i == 0) {
            if ()
        }
    }
    return 1;
}

int the_thing_2(int length) {
    return 1;
}

void solve(int n, string sick) {
    std::vector<int> islands;
    int curr_island_count = 0;
    int min_island_count = n;
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (sick.at(i) == '1') {
            curr_island_count++;
        } else if (curr_island_count != 0) {
            if (curr_island_count < min_island_count) {
                min_island_count = curr_island_count;
            }
            islands.push_back(curr_island_count);
            curr_island_count = 0;
        }
    }
    // for (int i = 0; i < islands.size(); i++) {
    //     cout << islands.at(i) << " ";
    // }
    // cout << "\n" << min_island_count << "\n";
    int max_nights = the_thing_2(min_island_count);
    cout << max_nights << "\n";

    for (int i = 0; i < islands.size(); i++) {
        count += the_thing(islands.at(i), max_nights);
        cout << count << " ";
    }
    cout << "\n";
    cout << count << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    string sick;
    cin >> sick;

    solve(n, sick);

    return 0;
}