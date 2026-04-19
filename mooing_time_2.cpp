#include <iostream>
#include <vector>
using namespace std;

void solve(long long n, std::vector<long long> moos) {
    std::vector<long long> count(n, 0);
    std::vector<long long> indiv_total(n, 0);
    for (long long i = n - 1; i >= 0; i--) {
        count.at(moos.at(i))++;
        indiv_total.at(moos.at(i)) = 0;
        for (long long x = 0; x < count.size(); x++) {
            if (x != moos.at(i) && count.at(x) >= 2) {
                indiv_total.at(moos.at(i))++;
            }
        }
    }
    long long total = 0;
    for (long long i = 0; i < indiv_total.size(); i++) {
        total += indiv_total.at(i);
    }
    cout << total << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    cin >> n;
    std::vector<long long> moos;
    for (long long i = 0; i < n; i++) {
        long long curr_moo;
        cin >> curr_moo;
        moos.push_back(curr_moo);
    }

    solve(n, moos);

    return 0;
}