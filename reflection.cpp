#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, u;
    cin >> n >> u;

    // Use a vector of strings for the grid
    vector<string> canvas(n);
    for (int i = 0; i < n; i++) {
        cin >> canvas[i];
    }

    // Helper lambda to calculate cost of a specific group (r, c)
    // We only pass the top-left coordinate (r, c) to this helper
    auto get_group_cost = [&](int r, int c) {
        int hashes = 0;
        // The 4 symmetric partners:
        if (canvas[r][c] == '#') hashes++;
        if (canvas[r][n - 1 - c] == '#') hashes++;
        if (canvas[n - 1 - r][c] == '#') hashes++;
        if (canvas[n - 1 - r][n - 1 - c] == '#') hashes++;

        // Cost is the minimum to make them all # or all .
        return min(hashes, 4 - hashes);
    };

    long long total_cost = 0;

    // Phase 1: Precompute the initial cost
    // We only iterate the top-left quadrant
    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < n / 2; j++) {
            total_cost += get_group_cost(i, j);
        }
    }

    // Print initial cost
    cout << total_cost << "\n";

    // Phase 2: Handle Updates
    for (int i = 0; i < u; i++) {
        int r, c;
        cin >> r >> c;
        r--; c--; // Convert 1-based to 0-based

        // Find the "representative" coordinates in the top-left quadrant
        // This maps any cell (r,c) to its partner in the top-left (0..N/2)
        int rep_r = min(r, n - 1 - r);
        int rep_c = min(c, n - 1 - c);

        // 1. Remove the OLD cost of this group
        total_cost -= get_group_cost(rep_r, rep_c);

        // 2. Perform the update
        if (canvas[r][c] == '#') canvas[r][c] = '.';
        else canvas[r][c] = '#';

        // 3. Add the NEW cost of this group
        total_cost += get_group_cost(rep_r, rep_c);

        cout << total_cost << "\n";
    }

    return 0;
}