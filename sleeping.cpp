#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int combine(int n_value, std::vector<int> curr_list) {
    int maximum = -1;
    for (int i = 0; i < n_value; i++) {
        if (curr_list.at(i) > maximum) {
            maximum = curr_list.at(i);
        }
    }
    int current_sum = 0;
    int count = 0;
    bool changed = false;
    // cout << "max: " << maximum << " ";
    std::vector<int> new_list;
    for (int i = 0; i < n_value; i++) {
        if (current_sum != 0) count++;
        current_sum += curr_list.at(i);


        if (current_sum > maximum) {
            changed = true;
            new_list.push_back(current_sum);
            current_sum = 0;
        }
    }

    std::reverse(new_list.begin(), new_list.end());
    if (current_sum > 0 && current_sum < maximum) {
        count += combine(new_list.size(), new_list);
    }
    if (changed) {
        return combine(new_list.size(), new_list) + count;
    }
    return count;
}

void solve(int t, std::vector<int> n_values, std::vector<std::vector<int> > all_lists) {
    for (int index = 0; index < t; index++) {
        cout << combine(n_values.at(index), all_lists.at(index)) << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    std::vector<int> n_values(t);
    std::vector<std::vector<int> > all_lists(t);
    for (int i = 0; i < t; i++) {
        cin >> n_values.at(i);
        std::vector<int> current_row(n_values.at(i));
        for (int x = 0; x < n_values.at(i); x++) {
            cin >> current_row.at(x);
        }
        all_lists.at(i) = current_row;
    }

    solve(t, n_values, all_lists);

    return 0;
}