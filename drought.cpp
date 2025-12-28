#include <iostream>
#include <vector>
using namespace std;

void solve(int t, std::vector<int> n_values, std::vector<std::vector<long long> > h_values) {
    for (int t_index = 0; t_index < t; t_index++) {
        if (n_values.at(t_index) == 0 || n_values.at(t_index) == 1) {
            cout << 0 << "\n";
            continue;
        }
        // if (n_values.at(t_index) % 2 == 1) {
        //     cout << -1 << "\n";
        //     continue;
        // }
        bool finished = false;
        bool negative = false;
        int corn_bags = 0;
        while (!finished) {
            finished = true;
            bool f = false;
            for (int i = 0; i < h_values.at(t_index).size(); i++) { //
                for (int x = 0; x < h_values.at(t_index).size(); x++) {
                    if (i != x && h_values.at(t_index).at(i) != h_values.at(t_index).at(x)) {
                        finished = false;
                    }
                }
                if (h_values.at(t_index).at(i) < 0) {
                    negative = true;
                    f = true;
                }
            }
            // cout << finished << f << negative << corn_bags << "\n";
            if (f) finished = true;
            corn_bags ++;

            int highest_index = -1;
            long long highest_value = -1;
            for (int i = 0; i < n_values.at(t_index); i++) {
                if (h_values.at(t_index).at(i) > highest_value) {
                    highest_value = h_values.at(t_index).at(i);
                    highest_index = i;
                }
            }

            if (highest_index == 0) {
                h_values.at(t_index).at(highest_index) --;
                h_values.at(t_index).at(highest_index + 1) --;
            } else if (highest_index == n_values.at(t_index) - 1) {
                h_values.at(t_index).at(highest_index) --;
                h_values.at(t_index).at(highest_index - 1) --;
            } else {
                h_values.at(t_index).at(highest_index) --;
                if (h_values.at(t_index).at(highest_index - 1) >= h_values.at(t_index).at(highest_index + 1)) {
                    h_values.at(t_index).at(highest_index - 1) --;
                } else {
                    h_values.at(t_index).at(highest_index + 1) --;
                }
            }

            // for (int i = 0; i < n_values.at(t_index); i++) {
            //     cout << h_values.at(t_index).at(i) << " ";
            // }
            // cout << "\n";
        }
        if (negative) {
            cout << -1 << "\n";
        } else {
            cout << (corn_bags - 1) * 2 << "\n";
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // freopen("problemname.in", "r", stdin);
    // freopen("problemname.out", "w", stdout);

    int t;
    std::vector<int> n_values;
    std::vector<std::vector<long long> > h_values;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int curr_n_value;
        cin >> curr_n_value;
        n_values.push_back(curr_n_value);
        h_values.push_back(std::vector<long long>());
        for (int x = 0; x < curr_n_value; x++) {
            int curr_h_value;
            cin >> curr_h_value;
            h_values.at(i).push_back(curr_h_value);
        }
    }
    solve(t, n_values, h_values);

    return 0;
}