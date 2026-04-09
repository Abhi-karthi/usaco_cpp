#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int money = 1;
    // cout << "value: " << (std::to_string(234).at(std::to_string(234).size() - 1) == '8') << "\n";
    for (int i = 1; i < n+1; i++) {
        if (std::to_string(i).at(std::to_string(i).size() - 1) == '8') {
            money = money / 2;
        }
        if (i % 3 == 0) {
            money = money + i;
        }
        if (i % 2 == 0) {
            money += static_cast<int>(money*0.1);
        }
        // cout << money << " " << i << "\n";
    }
    cout << money << "\n";
    return 0;
}