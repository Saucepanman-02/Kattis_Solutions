#include <bits/stdc++.h>

using namespace std;

#define speedup ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define usopen(file) do{freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);}while(0);
#define ll long long
#define db double
#define pii pair<int, int>
#define pdd pair<db, db>
#define vi vector<int>
#define vll vector<ll>
#define pll pair<ll, ll>
#define f first
#define s second
#define pdi pair<db, int>

int main() {
    int n;
    while (cin >> n && n) {
        int m; cin >> m;
        vector<vi> dist(n, vi(n, 1e9));
        for (int i = 0; i < m; i++) {
            int u, v; cin >> u >> v;
            dist[u][v] = dist[v][u] = 0;
        }
        for (int i = 0; i < n; i++) {
            dist[i][i] = 0;
        }
        vector<vi> dp((1<<n), vi(n, -1));
        dp[1][0 ] = 1;
        int ans = 1;
        for (int mask = 1; mask < (1<<n); mask++) {
            for (int u = 1; u < n; u++) {
                if (mask&(1<<u)) {
                    for (int v = 0; v < n; v++) {
                        if (mask&(1<<v) && u != v) {
                            if (dp[mask^(1<<u)][v] == 1 && dist[v][u] == 0) {
                                dp[mask][u] = 1;
                            }
                        }
                    }
                }
            }
        }
        for (int mask = 1; mask < (1<<n); mask++) {
            for (int u = 1; u < n; u++) {
                if (mask&1 && dp[mask][u] == 1 && dist[u][0] == 0) {
                    ans = max(ans, __builtin_popcount(mask));
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
