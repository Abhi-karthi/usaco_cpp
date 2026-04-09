#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c;
    cin >> a >> b >> c;
    int first_difference = c - b;
    int second_difference = b - a;

    if (first_difference == 1 && second_difference == 1) cout << 0 << "\n";
    else if (first_difference == 2 || second_difference == 2) cout << 1 << "\n";
    else cout << 2 << "\n";

    if (first_difference > second_difference) {
        cout << first_difference - 1 << "\n";
    } else {
        cout << second_difference - 1 << "\n";
    }

    return 0;
}