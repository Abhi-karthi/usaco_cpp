#include <iostream>
#include <vector>
using namespace std;

void solve(vector<long long>& list) {
    if (list.size() % 2 == 1) {
        long long sum = 0;
        bool alternate = true;
        for (const long long i : list) {
            if (alternate) {
                sum += i;
            } else {
                sum -= i;
            }
            alternate = !alternate;
        }

        if (sum < 0) {
            cout << -1 << "\n";
            return;
        }
        if (list.empty()) {
            cout << 0 << "\n";
            return;
        }
        long long first = sum;
        long long second = 0;
        long long count = 0;
        long long doublee = true;
        for (long long i = 0; i < list.size(); i++) {
            list.at(i) -= second;
            first = list.at(i)-sum;
            list.at(i) -= first;
            second = first;
            if (doublee) {
                count += first;
                doublee = false;
            }
            count += first;
        }

        cout << count << "\n";
        return;
    }
    long long sum = 0;
    bool alternate = true;
    for (const long long i : list) {
        if (alternate) {
            sum += i;
        } else {
            sum -= i;
        }
        alternate = !alternate;
    }

    if (sum != 0) {
        cout << -1 << "\n";
        return;
    }
    if (list.empty()) {
        cout << 0 << "\n";
        return;
    }
    long long first = 0;
    long long second = 0;
    long long count = 0;
    long long doublee = true;
    for (long long i = 0; i < list.size(); i++) {
        long long ops = list[i] -
    }

    cout << count << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t;
    cin >> t;
    vector<vector<long long>> lists(t);
    for (long long i = 0; i < t; i++) {
        long long n;
        cin >> n;
        vector<long long> list(n);
        for (long long x = 0; x < n - 2; x++) {
            cin >> list.at(x);
        }
        lists.at(i) = list;
    }

    for (vector<long long> i : lists) {
        solve(i);
    }

    return 0;
}