#include <iostream>
#include <vector>

using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> flowers(n);
    for (int i = 0; i < n; i++) {
        cin >> flowers[i];
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            double sum = 0;
            for (int x = i; x <= j; x++) {
                sum += flowers[x];
            }
            double average = sum / (j - i + 1);
            for (int x = i; x <= j; x++) {
                if (flowers[x] == average) {
                    count++;
                    // cout << i << " " << j << "\n";
                    break;
                }
            }
        }
    }

    cout << count << "\n";

    return 0;
}