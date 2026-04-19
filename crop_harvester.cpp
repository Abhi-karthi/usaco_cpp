#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    pair<int, int> p1;
    pair<int, int> p2;
    pair<int, int> p3;
    pair<int, int> p4;

    cin >> p1.first >> p1.second >> p2.first >> p2.second >> p3.first >> p3.second >> p4.first >> p4.second;

    if ((p1.second >= p3.second && p2.second <= p4.second) || (p1.first >= p3.first && p2.second <= p4.second)) {
        if ((p3.first <= p1.first && p1.first <= p4.first && p3.second <= p1.second && p1.second <= p4.second) && (p3.first <= p2.first && p2.first <= p4.first && p3.second <= p2.second && p2.second <= p4.second)) {
            cout << 0 << "\n";
            return 0;
        } else if ((p3.first <= p1.first && p1.first <= p4.first && p3.second <= p1.second && p1.second <= p4.second) || (p3.first <= p2.first && p2.first <= p4.first && p3.second <= p2.second && p2.second <= p4.second)) {
            int overlap_width = max(0, min(p2.first, p4.first)) - max(p1.first, p3.first);
            int overlap_height = max(0, min(p2.second, p4.second)) - max(p1.second, p3.second);
            int overlap_area = overlap_height * overlap_width;
            int total_area = ((p2.second - p1.second) * (p2.first - p1.first));
            cout << total_area - overlap_area << "\n";
            return 0;
        }
    }

    cout << (p2.second - p1.second) * (p2.first - p1.first) << "\n";

    return 0;
}