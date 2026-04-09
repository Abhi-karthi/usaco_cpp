#include <iostream>
#include <vector>
#include <utility>
using namespace std;1
void solve(int n, long long t, vector<pair<long long, int>> main_list) {
    long long c = 0;
    long long a = t;
    for (int i = 0; i < n - 1; i++) {
        long long difference = main_list.at(i + 1).first - main_list.at(i).first;
        c += main_list.at(i).second - difference;
        if (c < 0) {
            a += c;
            c = 0;
        }
    }
    c += main_list.at(n-1).second;
    if (c-(t-main_list.at(n-1).first) > 0) {
        cout << a << "\n";
    }
    cout << a + (c-(t-main_list.at(n-1).first)) - 1 << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    long long t;
    cin >> n >> t;
    vector<pair<long long, int>> main_list(n);
    for (int i = 0; i < n; i++) {
        cin >> main_list.at(i).first >> main_list.at(i).second;
    }
    solve(n, t, main_list);
    return 0;
}