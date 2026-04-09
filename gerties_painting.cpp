#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> numbers(4);
    cin >> numbers.at(0) >> numbers.at(1) >> numbers.at(2) >> numbers.at(3);
    if (numbers.at(2) > numbers.at(1) || numbers.at(3) < numbers.at(0)) {
        cout << numbers.at(1) - numbers.at(0) + numbers.at(3) - numbers.at(2) << "\n";
        return 0;
    }
    int least = 101;
    int max = -1;
    for (int i = 0; i < 4; i++) {
        if (numbers.at(i) < least) least = numbers.at(i);
        if (numbers.at(i) > max) max = numbers.at(i);
    }

    cout << max - least << "\n";

    return 0;
}