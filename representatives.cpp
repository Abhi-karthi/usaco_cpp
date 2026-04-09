#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    string groups;
    cin >> groups;
    std::vector<int> interns(n);
    for (int i = 0; i < n; i++) {
        cin >> interns.at(i);
        // interns.at(i)--;
    }

    int last_g = -1;
    int last_h = -1;
    int first_g = -1;
    int first_h = -1;
    for (int i = 0; i < n; i++) {
        if (groups.at(i) == 'G') last_g = i;
        else if (groups.at(i) == 'H') last_h = i;
        if (first_g == -1 && groups.at(i) == 'G') {
            first_g = i;
        } else if (first_h == -1 && groups.at(i) == 'H') {
            first_h = i;
        }
    }
    // cout << first_g << " " << last_g << " " << first_h << " " << last_h;

    int count = 0;
    for (int i = 0; i < first_h; i++) {
        if (first_h < interns.at(i) || (i == 0 && last_g < interns.at(0))) {
            count ++;
        }
    }
    for (int i = 0; i < first_g; i++) {
        if (first_g < interns.at(i) || (i == 0 && last_h < interns.at(0))) {
            count ++;
        }
    }

    cout << count << "\n";

    return 0;
}