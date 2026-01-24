#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("blocks.in", "r", stdin);
    freopen("blocks.out", "w", stdout);

    int n;
    cin >> n;
    std::vector<int> values(26, 0);
    std::vector<char> letters = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    std::vector<std::vector<string> > words;

    for (int i = 0; i < n; i++) {
        string first_word, second_word;
        cin >> first_word >> second_word;
        std::vector<int> curr_values1(26, 0);
        std::vector<int> curr_values2(26, 0);
        for (int x = 0; x < first_word.size(); x++) {
            auto it = std::find(letters.begin(), letters.end(), first_word.at(x));
            int index = std::distance(letters.begin(), it);
            curr_values1.at(index)++;
        }
        for (int x = 0; x < second_word.size(); x++) {
            auto it = std::find(letters.begin(), letters.end(), second_word.at(x));
            int index = std::distance(letters.begin(), it);
            curr_values2.at(index)++;
        }
        for (int x = 0; x < curr_values1.size(); x++) {
            int best = std::max(curr_values2[x], curr_values1[x]);
            values.at(x) += best;
        }
    }

    for (int i = 0; i < values.size(); i++) {
        cout << values.at(i) << "\n";
    }

    return 0;
}