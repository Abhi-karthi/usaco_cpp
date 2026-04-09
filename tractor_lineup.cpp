#include <iostream>
using namespace std;

void solve(int n, int even_count, int odd_count) {
    if (abs(odd_count - even_count) <= 1) {
        cout << n << "\n";
    } else if (even_count > odd_count + 1) {
        cout << odd_count + odd_count + 1 << "\n";
    } else if (odd_count > even_count + 1) {
        while (abs(odd_count - even_count) > 1) {
            // cout << odd_count << " " << even_count << "\n";
            // cout << odd_count << " " << even_count << "\n";
            odd_count -= 2;
            even_count ++;

        }
        // cout << odd_count << " " << even_count << "\n";
        cout << even_count + odd_count << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int even_count = 0;
    int odd_count = 0;
    for (int i = 0; i < n; i++) {
        int id;
        cin >> id;
        if (id % 2 == 0) {
            even_count++;
        } else {
            odd_count++;
        }
    }

    solve(n, even_count, odd_count);

    return 0;
}