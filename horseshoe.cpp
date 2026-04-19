#include <iostream>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    set<int> numberss;
    for (int i = 0; i < 4; i++) {
        int n;
        cin >> n;
        numberss.insert(n);
    }

        cout << 4 - numberss.size() << "\n";

    return 0;
}