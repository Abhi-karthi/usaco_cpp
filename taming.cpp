#include <iostream>
#include <vector>
using namespace std;

void solve(int t, std::vector<int> current_count_list) {
    bool last_counted_valid = false;
    int last_counted = -1;
    int last_counted_index_distance = -1;
    for (int i = current_count_list.size() - 1; i >= 0; i--) {
        if (current_count_list.at(i) != -1) {
            last_counted_index_distance ++;
            if (last_counted_valid && current_count_list.at(i) != last_counted-last_counted_index_distance) {
                cout << -1 << "\n";
                return;
            }
            last_counted = current_count_list.at(i);
            last_counted_index_distance = 0;
            last_counted_valid = true;
        } else {
            if (last_counted_valid) {
                last_counted_index_distance ++;
                current_count_list.at(i) = last_counted - last_counted_index_distance;
                if (last_counted_index_distance == last_counted) { last_counted_valid = false; }
            }
        }
    }

    if (current_count_list.at(0) == -1) {
        current_count_list.at(0) = 0;
    } else if (current_count_list.at(0) != 0) {
        cout << -1 << "\n";
        return;
    }

    int break_counter = 1;
    int not_sure_counter = 0;
    for (int i = 1; i < current_count_list.size(); i++) {
        if (current_count_list.at(i) == 0) break_counter ++;
        else if (current_count_list.at(i) == -1) not_sure_counter ++;
    }

    cout << break_counter << " " << break_counter + not_sure_counter << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("taming.in", "r", stdin);
    freopen("taming.out", "w", stdout);

    int n;
    cin >> n;
    std::vector<int> current_count_list;
    for (int i = 0; i < n; i++) {
        int curr_count;
        cin >> curr_count;
        current_count_list.push_back(curr_count);
    }
    solve(n, current_count_list);

    return 0;
}