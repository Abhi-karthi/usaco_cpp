#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<string> answers;
    for (int testcases = 0; testcases < n; testcases++) {
        string main_str;
        cin >> main_str;
        int r = 0;
        int l = 0;
        for (int x_val = 1; x_val < main_str.size(); x_val++) {
            const char x = main_str[x_val];
            const char prev = main_str[x_val - 1];
            if (prev == 'N') {
                if (x == 'W') l++;
                else if (x == 'E') r++;
            } else if (prev == 'E') {
                if (x == 'N') l++;
                else if (x == 'S') r++;
            } else if (prev == 'S') {
                if (x == 'E') l++;
                else if (x == 'W') r++;
            } else if (prev == 'W') {
                if (x == 'S') l++;
                else if (x == 'N') r++;
            }
        }

        if (l > r) answers.emplace_back("CCW");
        else answers.emplace_back("CW");
    }

    for (const auto& i : answers) {
        cout << i << "\n";
    }

    return 0;
}