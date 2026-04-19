#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool is_palindrome(int number) {
    string number_in_string = std::to_string(number);
    // cout << "1";
    for (int i = 0; i < number_in_string.size(); i++) {
        if (number_in_string.at(i) != number_in_string.at(number_in_string.size() - i - 1)) { return false; }
    }
    // cout << 2;
    return true;
}

void solve(int t, std::vector<int> sizes) {
    for (int i = 0; i < t; i++) {
        int current_size = sizes.at(i);
        char turn = 'B';
        char opposite_turn = 'E';
        while (current_size > 0) {
            // cout << current_size << " ";
            if (is_palindrome(current_size)) {
                current_size = 0;
            } else if (is_palindrome(current_size - 10) && current_size - 10 > 0) {
                current_size = 10;
            } else {
                current_size --;
            }
            std::swap(turn, opposite_turn);
        }
        cout << opposite_turn << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    std::vector<int> sizes;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int current_size;
        cin >> current_size;
        sizes.push_back(current_size);
    }
    solve(t, sizes);

    return 0;
}