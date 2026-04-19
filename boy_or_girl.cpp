#include <iostream>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string mystr;
    cin >> mystr;

    set<char> myset;
    for (auto i : mystr) {
        myset.insert(i);
    }

    if (myset.size() % 2 == 0) {
        cout << "CHAT WITH HER!";
        return 0;
    }
    cout << "IGNORE HIM!";

    return 0;
}