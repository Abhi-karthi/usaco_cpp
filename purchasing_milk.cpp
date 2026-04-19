#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    std::vector<int> a_values(n);
    for (int i = 0; i < n; i++) {
        cin >> a_values.at(i);
    }

    std::vector<int> queries(q);
    for (int i = 0; i < q; i++) {
        cin >> queries.at(i);
    }

    std::pair<int, int> best_deal;
    double helper = -1;
    for (int i = 0; i < a_values.at(i); i++) {
        if (pow(2, i) / a_values.at(i) > helper) {
            best_deal.first = pow(2, i);
            best_deal.second = a_values.at(i);
        }
    }

    for (int i = 0; i < q; i++) {
        int buckets = queries.at(i);
        int money_spent = 0;
        if (buckets >= best_deal.first) {
            money_spent = best_deal.ououou
        }
    }

    return 0;
}