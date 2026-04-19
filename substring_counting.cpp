#include <iostream>
#include <string>
#include <numeric>
#include <vector>
using namespace std;

int value(char character) {
    std::vector<char> alphabet(26);
    std::iota(alphabet.begin(), alphabet.end(), 'A');
    for (int i = 0; i < 26; i++) {
        if (alphabet.at(i) == character) {
            return i;
        }
    }
    return -1;
}

void solve(int n, string main_string) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int x = i + 1; x < n; x++) {
            if (value(main_string.at(x)) > value(main_string.at(i))) {
                count ++;
            }
        }
    }
    cout << count << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    string main_string;
    cin >> n >> main_string;

    solve(n, main_string);

    return 0;
}