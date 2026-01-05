#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve(int n, std::vector<int> a, std::vector<int> b, std::vector<int> g) {
    int current_cup = 1;
    std::vector<int> guess_count = {0, 0, 0};
    for (int i = 0; i < n; i++) {
        if (a.at(i) == current_cup) {
            current_cup = b.at(i);
        } else if (b.at(i) == current_cup) {
            current_cup = a.at(i);
        }
        if (current_cup == g.at(i)) {
            guess_count.at(0)++;
        }
    }

    current_cup = 2;
    for (int i = 0; i < n; i++) {
        if (a.at(i) == current_cup) {
            current_cup = b.at(i);
        } else if (b.at(i) == current_cup) {
            current_cup = a.at(i);
        }
        if (current_cup == g.at(i)) {
            guess_count.at(1)++;
        }
    }

    current_cup = 3;
    for (int i = 0; i < n; i++) {
        if (a.at(i) == current_cup) {
            current_cup = b.at(i);
        } else if (b.at(i) == current_cup) {
            current_cup = a.at(i);
        }
        if (current_cup == g.at(i)) {
            guess_count.at(2)++;
        }
    }

    int max_guess = guess_count.at(0);
    for (int i = 1; i < guess_count.size(); i++) {
        if (guess_count.at(i) > max_guess) {
            max_guess = guess_count.at(i);
        }
    }

    cout << max_guess << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("shell.in", "r", stdin);
    freopen("shell.out", "w", stdout);

    int n;
    std::vector<int> a;
    std::vector<int> b;
    std::vector<int> g;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int curr_a, curr_b, curr_g;
        cin >> curr_a >> curr_b >> curr_g;
        a.push_back(curr_a);
        b.push_back(curr_b);
        g.push_back(curr_g);
    }
    solve(n, a, b, g);

    return 0;
}