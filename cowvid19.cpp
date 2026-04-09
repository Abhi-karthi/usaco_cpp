#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> cows(n);
    for (int i = 0; i < n; i++) {
        cin >> cows.at(i);
    }

    vector<int> maximums(n, 0);
    int index = 0;
    for (int cow: cows) {
        int spread = 0;
        vector<int> ill;
        ill.push_back(cow);
        int range_a = cow;
        int range_b = cow;
        int number = 1;
        int prev_number = -1;
        while (number != prev_number) {
            spread++;
            int lowest_ill = 1000000001;
            int highest_ill = -1;
            for (int ill_cow : ill) {
                if (ill_cow < lowest_ill) lowest_ill = ill_cow;
                if (ill_cow > highest_ill) highest_ill = ill_cow;
            }
            range_a = lowest_ill - spread;
            range_b = highest_ill + spread;
            prev_number = number;
            number = 0;
            for (int cowa : cows) {
                if (cowa >= range_a && cowa <= range_b) {
                    ill.push_back(cowa);
                    number++;
                }
            }
            // cout << number << "\n";
        }
        maximums.at(index) = number;
        index++;
    }

    int max = -1;
    for (int i = 0; i < maximums.size(); i++) {
        if (maximums.at(i) > max) max = maximums.at(i);
    }

    cout << max << "\n";

    return 0;
}