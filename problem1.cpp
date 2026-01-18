#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void solve(int t, std::vector<long long> a, std::vector<long long> b, std::vector<int> ca, std::vector<int> cb, std::vector<int> fa) {
    for (int index = 0; index < t; index++) {
        long long add_a_value = 0;
        long long cb_long = static_cast<long long>(cb.at(index));
        long long ca_long = static_cast<long long>(ca.at(index));

        long long convert_1 = (b.at(index) / cb_long) * ca_long;
        long long remaining_b = b.at(index) % cb_long;
        long long total = convert_1 + a.at(index);
        long long original_total = total;
        long long solution = 0;
        if (total >= fa.at(index)) {
            cout << 0 << "\n";
            continue;
        }
        //
        // cout << remaining_b << "remainb" << "\n";
        // long long remaining_b_gain = ca_long - (cb_long - remaining_b);
        // if (remaining_b_gain < 1) {
        //     total += remaining_b_gain;
        //     solution += cb_long - remaining_b;
        //     if (total >= fa.at(index)) {
        //         cout << solution << "\n";
        //         continue;
        //     }
        // }

        // cout << "total:" << " " << total << "\n";

        if (cb_long < ca_long) {
            cout << fa.at(index) - total + solution << "\n";
        } else {
            // cout << "nermerator" << ca_long << "\n";
            long long divide = ((fa.at(index) - total) + ca_long - 1) / ca_long;

            long long left = (divide) * cb_long - remaining_b;
            // cout << "left: " << left << "\n";
            if (original_total + (divide*ca_long) - ca_long + 1 < fa.at(index)) {
                left++;
            }

            solution += left;
            cout << solution << "\n";
        }

    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    std::vector<long long> a;
    std::vector<long long> b;
    std::vector<int> ca;
    std::vector<int> cb;
    std::vector<int> fa;
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        long long curr_a;
        long long curr_b;
        int curr_ca;
        int curr_cb;
        int curr_fa;
        cin >> curr_a >> curr_b >> curr_ca >> curr_cb >> curr_fa;
        a.push_back(curr_a);
        b.push_back(curr_b);
        ca.push_back(curr_ca);
        cb.push_back(curr_cb);
        fa.push_back(curr_fa);
    }

    solve(t, a, b, ca, cb, fa);

    return 0;
}
