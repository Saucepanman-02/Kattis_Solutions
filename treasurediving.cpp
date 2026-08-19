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
#define ceil(n, r) (ll)((n+r-1)/r)
#define floor(n, r) (ll)(n/r);

vector<vector<pii>> g;
int n, m;

vll sssp(int u) {
    vi dist(n, 1e9);
    dist[u] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0, u});
    while (!pq.empty()) {
        pair<ll, int> cr = pq.top(); pq.pop();
        if (cr.f > dist[cr.s]) {
            continue;
        }
        for (auto &[v, w]: g[cr.s]) {
            if (dist[v] > dist[cr.s]+w) {
                dist[v] = dist[cr.s]+w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main() {
    speedup
    int t; cin >> t;
    while (t--) {
        cin >> n >> m;
        g.assign(n, vector<pii>());
        for (int i = 0; i < m; i++) {
            int u, v, w; cin >> u >> v >> w;
            g[u].push_back({v, w});
            g[v].push_back({u, w});
        }
        int k; cin >> k;
        vi a(k+1);
        for (int i = 0; i < k; i++) {
            cin >> a[i+1];
        }
        vector<vi> dist(k+1, vi(k+1));
        for (int i = 0; i <= k; i++) {
            vll d = sssp(a[i]);
            for (int j = 0; j <= k; j++) {
                dist[i][j] = d[a[j]];
            }
        }
        k++;
        vector<vll> dp((1<<k), vll(k, 1e9));
        dp[1][0] = 0;
        int tot; cin >> tot;
        int ans = 0;
        for (int mask = 1; mask < (1<<k); mask++) {
            for (int i = 1; i < k; i++) {
                if (mask&(1<<i)) {
                    for (int j = 0; j < k; j++) {
                        if (mask&(1<<j) && i != j) {
                            dp[mask][i] = min(dp[mask][i], dp[mask^(1<<i)][j]+dist[j][i]);
                        }
                    }
                    if (dp[mask][i]+dist[i][0] <= tot) {
                        ans = max(ans, __builtin_popcount(mask)-1);
                    }
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
