#include <format>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    string main_string;
    cin >> main_string;

    int max = 0;
    int min = 0;

    char prev_letter = '?';
    int fCount = 0;
    for (int i = 0; i < n; i++) {
        if (main_string[i] == 'F') {
            fCount++;
            continue;
        }
        if (prev_letter == '?') {
            max += fCount;
        } else if (main_string.at(i) == prev_letter) {
            max += fCount + 1;
            min += (fCount + 1) % 2;
        } else {
            max += fCount;
            min += fCount % 2;
        }
        fCount = 0;
        prev_letter = main_string.at(i);
    }
    max += fCount;

    if (prev_letter == '?') {
        max -= 1;
    }

    if (main_string.at(0) == 'F' || main_string.at(n-1) == 'F') {
        cout << max - min + 1 << "\n";
        for (int i = min; i < max + 1; i++) {
            cout << i << "\n";
        }
    } else {
        cout << (max - min)/2 + 1 << "\n";
        for (int i = min; i < max + 1; i+=2) {
            cout << i << "\n";
        }
    }

    return 0;
}