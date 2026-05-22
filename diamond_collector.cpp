#include <iostream>
#include <vector>

using namespace std;

void solve()

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<int> diamonds(n);

    for (int i = 0; i < n; i++) {
        cin >> diamonds[i];
    }

    return 0;
}