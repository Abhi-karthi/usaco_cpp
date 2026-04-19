#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string main;
    cin >> n >> main;

    vector<int> main_list;
    for (int i = 0; i < n - 1; i+=2) {
        if (main[i] == 'G' && main[i+1] == 'H') {
            main_list.push_back(0);
        } else if (main[i] == 'H' && main[i+1] == 'G') {
            main_list.push_back(1);
        }
    }

    // for (int i : main_list) {
    //     cout << i << " ";
    // }
    // cout << "\n";

    int flips = 0;
    for (int i = 0; i < main_list.size() - 1; i++) {
        if (main_list[i] != main_list[i+1]) {
            flips++;
        }
    }

    if (main_list.back() == 0) {
        flips++;
    }
    cout << flips << "\n";

    return 0;
}