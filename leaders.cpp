#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

void add_to_list(std::set<int>& g_leader_indexes, std::set<int>& h_leader_indexes, string cows, int index) {
    // cout << "pushed";
    if (cows.at(index) == 'G') {
        g_leader_indexes.insert(index);
        // cout << "pushed g";
    } else if (cows.at(index) == 'H') {
        h_leader_indexes.insert(index);
        // cout << "pushed h";
    }
}

bool is_in(std::set<int>& g_leader_indexes, std::set<int>& h_leader_indexes, string cows, int current_index) {
    if (cows.at(current_index) == 'G') {
        if (h_leader_indexes.count(current_index) == 1) return true;
    } else if (cows.at(current_index) == 'H') {
        if (g_leader_indexes.count(current_index) == 1) return true;
    }
    return false;
}

bool is_in2(std::set<int>& g_leader_indexes, std::set<int>& h_leader_indexes, string cows, int current_index, int checking_value) {
    if (cows.at(checking_value) == 'G') {
        if (h_leader_indexes.count(current_index) == 1) return true;
    } else if (cows.at(checking_value) == 'H') {
        if (g_leader_indexes.count(current_index) == 1) return true;
    }
    return false;
}

void solve(int n, string cows, std::vector<int> e) {
    std::set<int> g_leader_indexes;
    std::set<int> h_leader_indexes;
    for (int i = 0; i < n; i++) {
        bool contains_opposite = false;
        for (int x = e.at(i); x < n; x++) {
            if (cows.at(i) == cows.at(x)) {
                contains_opposite = true;
                break;
            }
        }
        if (!contains_opposite) {
            for (int x = 0; x < i; x++) {
                if (cows.at(i) == cows.at(x)) {
                    contains_opposite = true;
                    break;
                }
            }
        }

        if (!contains_opposite) {
            add_to_list(g_leader_indexes, h_leader_indexes, cows, i);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int x = i; x < e.at(i); x++) {
            if (is_in2(g_leader_indexes, h_leader_indexes, cows, x, i)) {
                add_to_list(g_leader_indexes, h_leader_indexes, cows, i);
            }
        }
    }
    // for (int i = 0; i < g_leader_indexes.size(); i++) {
    //     cout << g_leader_indexes.at(i) << " ";
    // }
    // cout << "\n";
    // for (int i = 0; i < h_leader_indexes.size(); i++) {
    //     cout << h_leader_indexes.at(i) << " ";
    // }
    // cout << "\n";

    cout << g_leader_indexes.size() * h_leader_indexes.size() << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    string cows;
    std::vector<int> e;

    cin >> n;
    cin >> cows;

    for (int i = 0; i < n; i++) {
        int curr_e;
        cin >> curr_e;
        e.push_back(curr_e);
    }

    solve(n, cows, e);

    return 0;
}