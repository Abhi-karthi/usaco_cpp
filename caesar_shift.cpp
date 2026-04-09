#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

char shift(char character, int shift) {
    std::vector<char> alphabet(26);
    std::iota(alphabet.begin(), alphabet.end(), 'a');
    for (int i = 0; i < 26; i++) {
        if (character == alphabet.at(i)) {
            // cout << alphabet.at((i + shift)%26) << "\n";
            if (shift + i > 25) {
                return alphabet.at((i + shift)%26);
            }
            return alphabet.at(i + shift);
        }
    }
    return 'a';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string letters;
    int k;
    cin >> letters >> k;

    string new_string = "";
    for (int i = 0; i < letters.size(); i++) {
        new_string += shift(letters.at(i), k);
    }
    cout << new_string << "\n";

    return 0;
}