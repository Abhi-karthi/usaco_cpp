#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Sensor {
    string type;
    int low, high;
};

int main() {
    // Standard USACO file I/O
    freopen("traffic.in", "r", stdin);
    freopen("traffic.out", "w", stdout);

    int n;
    cin >> n;

    vector<Sensor> sensors(n);
    for (int i = 0; i < n; i++) {
        cin >> sensors[i].type >> sensors[i].low >> sensors[i].high;
    }

    // --- 1. BACKWARD PASS (To find the starting traffic range) ---
    // Start with a very wide range
    int L = -999999, R = 999999;

    for (int i = n - 1; i >= 0; i--) {
        if (sensors[i].type == "none") {
            // Intersection: Narrow the range to what the sensor sees
            L = max(L, sensors[i].low);
            R = min(R, sensors[i].high);
        } else if (sensors[i].type == "on") {
            // Reversing "on": If traffic was added, there was LESS before
            L -= sensors[i].high;
            R -= sensors[i].low;
        } else if (sensors[i].type == "off") {
            // Reversing "off": If traffic was removed, there was MORE before
            L += sensors[i].low;
            R += sensors[i].high;
        }
        // Traffic count cannot be negative
        L = max(0, L);
    }
    cout << L << " " << R << endl;

    // --- 2. FORWARD PASS (To find the ending traffic range) ---
    // Reset range to wide again
    L = -999999, R = 999999;

    for (int i = 0; i < n; i++) {
        if (sensors[i].type == "none") {
            // Intersection
            L = max(L, sensors[i].low);
            R = min(R, sensors[i].high);
        } else if (sensors[i].type == "on") {
            // Forward "on": Traffic increases
            L += sensors[i].low;
            R += sensors[i].high;
        } else if (sensors[i].type == "off") {
            // Forward "off": Traffic decreases
            L -= sensors[i].high;
            R -= sensors[i].low;
        }
        L = max(0, L);
    }
    cout << L << " " << R << endl;

    return 0;
}