#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;
const int MAX_H = 17; // log2(10^5)

long long dp[100005][MAX_H]; // dp[u][h] = ways to form a PBT of height h rooted at u

void dfs(int u, int p, const vector<vector<int>>& adj) {
    dp[u][0] = 1; // A single node is a PBT of height 0

    for (int v : adj[u]) {
        if (v == p) continue;
        dfs(v, u, adj);
    }

    // A PBT of height h > 0 is formed by u + 2 children of height h-1
    for (int h = 1; h < MAX_H; ++h) {
        vector<long long> children_ways;
        for (int v : adj[u]) {
            if (v != p) children_ways.push_back(dp[v][h - 1]);
        }

        // We need to pick exactly 2 children to be PBTs of height h-1
        // and "cut" all other children (which are already valid PBTs).
        // Since the problem asks for a forest, if we don't pick a child,
        // we must cut the edge. A cut edge is only valid if the subtree
        // is ALREADY a valid forest of PBTs.

        // This requires a separate DP: ways[u][h] = total ways to make the
        // subtree at u a valid forest, where u is part of a PBT of height h.
    }
}

void solve() {
    cin >> N;
    adj.assign(N + 1, vector<int>());
    for (int i = 0; i < N - 1; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v); adj[v].push_back(u);
    }
    for(int i=0; i<=N; ++i) for(int j=0; j<MAX_D; ++j) dp[i][j][0] = dp[i][j][1] = 0;

    dfs(1, 0);
    long long ans = 0;
    for (int d = 0; d < MAX_D; ++d) ans = add(ans, dp[1][d][0]);
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while (T--) solve();
    return 0;
}