#include <iostream>
#include <string>
#include <vector>
using namespace std;

string delete_substring(const int start_index, const int end_index, string main_string) {
    return main_string.erase(start_index, end_index-start_index);
}

string operation(string main_string, const string& censor, string prev) {
    std::vector<int> first;
    std::vector<int> last;
    if (prev == main_string) {
        return main_string;
    }
    prev = main_string;
    for (int i = 0; i < main_string.size() - censor.size(); i++) {
        string combined_string = main_string.substr(i, censor.size());
        if (combined_string == censor) {
            first.push_back(i);
            last.push_back(i + static_cast<int>(censor.size()));
        }
    }
    for (int i = 0; i < first.size(); i++) {
        main_string = delete_substring(first.at(i) - (censor.size() * i), last.at(i) - (censor.size() * i), main_string);
    }
    return operation(main_string, censor, prev);
}

void solve(string &main_string, const string& censor) {
    if (main_string.empty()) {
        cout << main_string << "\n";
        return;
    }
    main_string = operation(main_string, censor, "");

    cout << main_string << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("censor.in", "r", stdin);
    freopen("censor.out", "w", stdout);

    string main_string;
    string censor;
    cin >> main_string >> censor;

    solve(main_string, censor);

    return 0;
}