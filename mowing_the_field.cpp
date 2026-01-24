#include <iostream>
#include <vector>
#include <set>
using namespace std;

void add_to_vector(std::vector<std::vector<int> >& covered, std::vector<int> previous, std::vector<int> current, char direction) {
    covered.push_back(previous);
    if (direction == 'N') {
        for (int i = previous.at(1) + 1; i < current.at(1); i++) {
            covered.push_back({current.at(0), i});
        }
    } else if (direction == 'E') {
        for (int i = previous.at(0) + 1; i < current.at(0); i++) {
            covered.push_back({i, current.at(1)});
        }
    } else if (direction == 'S') {
        for (int i = previous.at(1) - 1; i > current.at(1); i--) {
            covered.push_back({current.at(0), i});
        }
    } else if (direction == 'W') {
        for (int i = previous.at(0) - 1; i > current.at(0); i--) {
            covered.push_back({i, current.at(1)});
        }
    }

}

void solve(int n, std::vector<char> direction, std::vector<int> movement) {
    std::vector<std::vector<int> > covered = {};
    std::vector<int> current = {0, 0};
    std::vector<int> prev;
    for (int i = 0; i < n; i++) {
        prev = current;
        if (direction.at(i) == 'N') {
            current = {prev.at(0), prev.at(1) + movement.at(i)};
        } else if (direction.at(i) == 'E') {
            current = {prev.at(0) + movement.at(i), prev.at(1)};
        } else if (direction.at(i) == 'S') {
            current = {prev.at(0), prev.at(1) - movement.at(i)};
        } else if (direction.at(i) == 'W') {
            current = {prev.at(0) - movement.at(i), prev.at(1)};
        }
        add_to_vector(covered, prev, current, direction.at(i));
    }

    // for (int i = 0; i < covered.size(); i++) {
    //     for (int x = 0; x < covered.at(i).size(); x++) {
    //         cout << covered.at(i).at(x) << " ";
    //     }
    //     cout << "\n";
    // }

    std::set<int> times;
    bool overlap = false;
    for (int i = 0; i < covered.size(); i++) {
        for (int x = 0; x < covered.size(); x++) {
            if (x != i && covered.at(i) == covered.at(x)) {
                if (i - x >= 0) {
                    times.insert(i - x);
                }
                overlap = true;
            }
        }
    }
    if (!overlap) {
        cout << -1 << "\n";
        return;
    }
    // for (const int i : times) {
    //     cout << i << "\n";
    // }
    int min_value = *times.begin();
    if (min_value < 0) {
        min_value *= -1;
    }
    cout << min_value << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("mowing.in", "r", stdin);
    freopen("mowing.out", "w", stdout);

    int n;
    std::vector<char> direction;
    std::vector<int> movement;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char curr_direction;
        int curr_movement;
        cin >> curr_direction >> curr_movement;
        direction.push_back(curr_direction);
        movement.push_back(curr_movement);
    }

    solve(n, direction, movement);

    return 0;
}
