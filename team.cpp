#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int out = 0;
    for (int i = 0; i < n; i++) {
        int n1;
        int n2;
        int n3;
        int count = 0;
        cin >> n1 >> n2 >> n3;
        if (n1 == 1) count++;
        if (n2 == 1) count++;
        if (n3 == 1) count++;
        if (count >= 2) out++;
    }

    cout << out << "\n";

    return 0;
}