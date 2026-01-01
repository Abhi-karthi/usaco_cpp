#include <iostream>
#include <vector>
using namespace std;

void solve(int t, std::vector<int> n_values, std::vector<std::vector<int> > hay_values) {
    for (int i = 0; i < t; i++) {
        std::vector<std::vector<int> > number_count;
        // cout << "input finished";
        for (int x = 0; x < n_values.at(i); x++) {
            bool broke = false;
            // cout << "input finished2";
            for (int v = 0; v < number_count.size(); v++) {
                if (number_count.at(v).at(0) == hay_values.at(i).at(x)) {
                    number_count.at(v).at(1) ++;
                    broke = true;
                    break;
                }
            }
            if (!broke) {
                std::vector<int> new_number_count;
                new_number_count.push_back(hay_values.at(i).at(x));
                new_number_count.push_back(1);
                number_count.push_back(new_number_count);
            }
        }

        int half = n_values.at(i);
        if (half % 2 == 0) {
            half /= 2;
        } else {
            half -= 1;
            half /= 2;
        }

        // cout << "\n";
        // for (int x = 0; x < number_count.size(); x++) {
        //     for (int v = 0; v < number_count.at(x).size(); v++) {
        //         cout << number_count.at(x).at(v) << " ";
        //     }
        //     cout << n_values.at(x) << "    ";
        // }
        // cout << "\n";

        std::vector<int> solution;
        for (int x = 0; x < number_count.size(); x++) {
            if (number_count.at(x).at(1) >= half) {
                solution.push_back(number_count.at(x).at(0));
            }
        }

        if (!solution.empty()) {
            std::sort(solution.begin(), solution.end());
            for (int x = 0; x < solution.size(); x++) {
                cout << solution.at(x) << " ";
            }
            cout << "\n";
        } else {
            cout << -1 << "\n";
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    std::vector<int> n_values;
    std::vector<std::vector<int> > hay_values;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int curr_n_value;
        std::vector<int> curr_hay_value_vector;
        cin >> curr_n_value;
        n_values.push_back(curr_n_value);
        for (int x = 0; x < curr_n_value; x++) {
            int curr_hay_value;
            cin >> curr_hay_value;
            curr_hay_value_vector.push_back(curr_hay_value);
        }
        hay_values.push_back(curr_hay_value_vector);
    }

    // for (int i = 0; i < n_values.size(); i++) {
    //     cout << n_values.at(i) << " ";
    // }
    // cout << "\n";

    solve(t, n_values, hay_values);

    return 0;
}