#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    int answers[t];

    for (int i = 0; i < t; i++) {
        int num;
        cin >> num;
        if (num == 67) answers[i] = 66;
        else answers[i] = num + 1;
    }

    for (int i : answers) {
        cout << i << "\n";
    }

    return 0;
}