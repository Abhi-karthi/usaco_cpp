 #include <iostream>
#include <vector>
#include <numeric>
using namespace std;

void solve(string main_string) {
    std::vector<char> alphabet(26);
    std::iota(alphabet.begin(), alphabet.end(), 'A');
    int count = 0;
    for (int i = 0; i < 26; i++) {
        for (int x = i + 1; x < 26; x++) {
            if (i == x) continue;
            std::vector<int> vector1;
            std::vector<int> vector2;
            for (int v = 0; v < 52; v++) {
                if (main_string.at(v) == alphabet.at(i)) vector1.push_back(v);
            }
            for (int v = 0; v < 52; v++) {
                if (main_string.at(v) == alphabet.at(x)) vector2.push_back(v);
            }
            // cout << "vector1: " << vector1.at(0) << " " << vector1.at(1) << "\n";
            // cout << "vector2: " << vector2.at(0) << " " << vector2.at(1) << "\n";
                // cout << "validity: " << (vector1.at(0) < vector2.at(0) && vector1.at(1) > vector2.at(0) && vector1.at(1) < vector2.at(1)) << "\n";
                if ((vector1.at(0) < vector2.at(0) && vector1.at(1) > vector2.at(0) && vector1.at(1) < vector2.at(1)) || (vector2.at(0) < vector1.at(0) && vector2.at(1) > vector1.at(0) && vector2.at(1) < vector1.at(1))) {
                count++;
            }
        }
    }
    // count /= 2;
    // count++;
    cout << count << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("circlecross.in", "r", stdin);
    freopen("circlecross.out", "w", stdout);

    string main_string;
    cin >> main_string;

    solve(main_string);

    return 0;
}