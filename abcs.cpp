#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> numbers(7);
    for (int i = 0; i < 7; i++) {
        cin >> numbers[i];
    }
    // int count = 0;
    // int count2 = 0;
    // int count3 = 0;
    for (int a = 0; a < 7; a++) {
        // count3++;
        for (int b = 0; b < 7; b++) {
            for (int c = 0; c < 7; c++) {
                // count3++;
                for (int ab = 0; ab < 7; ab++) {
                    // count3++;
                    for (int bc = 0; bc < 7; bc++) {
                        // count3++;
                        for (int ca = 0; ca < 7; ca++) {
                            // count3++;
                            for (int abc = 0; abc < 7; abc++) {
                                // count3++;
                                vector<int> curr_numbers = {a, b, c, ab, bc, ca, abc};
                                bool break_ = false;
                                for (int i = 0; i < 7; i++) {
                                    for (int x = i + 1; x < 7; x++) {
                                        if (curr_numbers.at(i) == curr_numbers.at(x)) break_ = true;
                                    }
                                }
                                if (break_) {
                                    // count2++;
                                    continue;
                                }
                                // count++;
                                if (numbers[a] + numbers[b] == numbers[ab] && numbers[a] + numbers[c] == numbers[ca] && numbers[b] + numbers[c] == numbers[bc] && numbers[a] + numbers[b] + numbers[c] == numbers[abc]) {
                                    int n1 = numbers[a];
                                    int n2 = numbers[b];
                                    int n3 = numbers[c];
                                    if (n2 <= n1 && n1 <= n3) {
                                        cout << n2 << " " << n1 << " " << n3;
                                    } else if (n1 <= n3 && n3 <= n2) cout << n1 << " " << n3 << " " << n2;
                                    else if (n2 <= n3 && n3 <= n1) cout << n2 << " " << n3 << " " << n1;
                                    else if (n3 <= n1 && n1 <= n2) cout << n3 << " " << n1 << " " << n2;
                                    else if (n3 <= n2 && n2 <= n1) cout << n3 << " " << n2 << " " << n1;
                                    else cout << n1 << " " << n2 << " " << n3;

                                    cout << "\n";
                                    return 0;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    cout << -1 << "\n";
    return 0;
}