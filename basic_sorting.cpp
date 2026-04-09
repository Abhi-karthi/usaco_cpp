#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    std::vector<int> main_list;
    for (int i = 0; i < n; i++) {
        int current_int;
        cin >> current_int;
        main_list.push_back(current_int);
    }
    sort(main_list.begin(), main_list.end());
    for (int i = 0; i < n; i++) {
        cout << main_list.at(i) << " ";
    }
    cout << "\n";
    return 0;
}