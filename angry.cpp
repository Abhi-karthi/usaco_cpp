#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

void solve(int n, std::vector<long long> haybale_numbers) {
    if (n == 1) {
        cout << 1 << "\n";
        return;
    }
    for (int end = 0; end < n; end++) {
        int least_index = end;
        for (int i = end; i < n; i++) {
            if (haybale_numbers.at(i) < haybale_numbers.at(least_index)) {
                least_index = i;
            }
        }
        std::swap(haybale_numbers[least_index], haybale_numbers[end]);
    }

    {
        for (int i = 0; i < n; i++) {
            cout << haybale_numbers.at(i) << " ";
        }
        cout << "\n";
    }

    std::vector<long long> neighbor_length;
    neighbor_length.push_back(haybale_numbers.at(1) - haybale_numbers.at(0));
    for (int i = 1; i < n - 1; i++) {
        neighbor_length.push_back((haybale_numbers.at(i) - haybale_numbers.at(i-1)) + (haybale_numbers.at(i + 1) - haybale_numbers.at(i)));
    }
    neighbor_length.push_back(haybale_numbers.at(n - 1) - haybale_numbers.at(n - 2));

    int greatest_neighbor_length_index = 0;
    for (int i = 1; i < n; i++) {
        if (neighbor_length.at(i) > neighbor_length.at(greatest_neighbor_length_index)) greatest_neighbor_length_index = i;
    }

    int bomb_size = 1;
    bool finished = false;
    std::vector<int> bombed = {greatest_neighbor_length_index};
    std::vector<int> new_bombed = {greatest_neighbor_length_index};
    while (!finished) {
        bool temp = true;
        for (int i = 0; i < bombed.size(); i++) {
            bool here = false;
            cout << bombed.at(i) << " ";
            if (bombed.at(i) == 0) {
                if (haybale_numbers.at(bombed.at(i)) + bomb_size >= haybale_numbers.at(bombed.at(i) + 1)) {
                    temp = false;
                    for (int x = 0; x < bombed.size(); x++) {
                        if (bombed.at(i) + 1 == bombed.at(x)) here = true;
                    }
                    if (!here) new_bombed.push_back(bombed.at(i) + 1);
                }
            } else if (bombed.at(i) == n - 1) {
                if (haybale_numbers.at(bombed.at(i)) - bomb_size <= haybale_numbers.at(bombed.at(i) - 1)) {
                    temp = false;
                    for (int x = 0; x < bombed.size(); x++) {
                        if (bombed.at(i) - 1 == bombed.at(x)) here = true;
                    }
                    if (!here) new_bombed.push_back(bombed.at(i) - 1);
                }
            } else {
                if (haybale_numbers.at(bombed.at(i)) - bomb_size <= haybale_numbers.at(bombed.at(i) - 1)) {
                    temp = false;
                    for (int x = 0; x < bombed.size(); x++) {
                        if (bombed.at(i) - 1 == bombed.at(x)) here = true;
                    }
                    if (!here) new_bombed.push_back(bombed.at(i) - 1);
                }
                if (haybale_numbers.at(bombed.at(i)) + bomb_size >= haybale_numbers.at(bombed.at(i) + 1)) {
                    temp = false;
                    for (int x = 0; x < bombed.size(); x++) {
                        if (bombed.at(i) + 1 == bombed.at(x)) here = true;
                    }
                    if (!here) new_bombed.push_back(bombed.at(i) + 1);
                }
            }
        }
        bombed = new_bombed;
        bomb_size ++;
        finished = temp;
    }
    cout << bombed.size() << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("angry.in", "r", stdin);
    freopen("angry.out", "w", stdout);

    int n;
    cin >> n;
    std::vector<long long> haybale_numbers;
    for (int i = 0; i < n; i++) {
        long long curr_number;
        cin >> curr_number;
        haybale_numbers.push_back(curr_number);
    }
    solve(n, haybale_numbers);

    return 0;
}