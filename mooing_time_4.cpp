#include <iostream>
#include <vector>
#include <string>
using namespace std;

void solve(int n, string main_string, int k) {
    std::vector<char> main_list(n);
    int o_count = 0;

    for (int i = main_string.size() - 1; i >= 0; i--) {
        char curr = main_string.at(i);
        if (o_count % 2 == 1) {
            if (curr == 'O') curr = 'M';
            else if (curr == 'M') curr = 'O';
        }
        main_list.at(i) = curr;
        if (curr == 'O') {
            o_count ++;
        }
    }
    string final_string;

    for (int i = 0; i < main_list.size(); i++) {
        final_string += main_list.at(i);
    }

    // cout << final_string << "\n";
    // string curr_string;
    // std::vector<int> switches;
    // for (int i = 0; i < final_string.size(); i++) {
    //     if (final_string.at(i) == 'M') {
    //         curr_string += 'M';
    //     } else {
    //         for (int x = 0; x < switches.size(); x++) {
    //             switches.at(x)++;
    //         }
    //         curr_string += 'O';
    //     }
    //     switches.push_back(0);
    // }
    // for (int i = 0; i < switches.size(); i++) {
    //     if (switches.at(i) % 2 == 1) {
    //         if (curr_string.at(i) == 'O') curr_string.at(i) = 'M';
    //         else if (curr_string.at(i) == 'M') curr_string.at(i) = 'O';
    //     }
    // }
    // if (curr_string == main_string) cout << "YES" << "\n";
    // else cout << "NO" << "\n";
    cout << "YES" << "\n";
    if (k == 1) {
        cout << final_string << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, k;
    cin >> t >> k;
    std::vector<int> n_values(t);
    std::vector<string> string_values(t);

    for (int i = 0; i < t; i++) {
        // int n;
        cin >> n_values.at(i);
        // string main_string;
        cin >> string_values.at(i);

    }
    for (int i = 0; i < t; i++) {
        solve(n_values.at(i), string_values.at(i), k);
    }

    return 0;
}