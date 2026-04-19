#include <iostream>
#include <string>

using namespace std;

int find_index(const char curr, const string& alphabet) {
    for (int i = 0; i < alphabet.size(); i++) {
        if (alphabet[i] == curr) {
            return i;
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string alphabet;
    string said;
    cin >> alphabet >> said;

    int count = 1;
    int prev_index = -1;
    for (int i = 0; i < said.size(); i++) {
        // cout << count << "\n";
        if (find_index(said.at(i), alphabet) <= prev_index) {
            count++;
        }
        prev_index = find_index(said.at(i), alphabet);
    }

    cout << count << "\n";

    return 0;
}