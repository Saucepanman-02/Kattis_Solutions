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
#define LSOne(x) (x&(x-1))^x


void solve() {
    int n, k; cin >> n >> k;
    vector<vi> dist(n, vi(n, 1));
    for (int i = 0; i < k; i++) {
        int u, v; cin >> u >> v; u--, v--;
        dist[u][v] = dist[v][u] = 1e9;
    }
    vector<vll> dp(1<<(n), vll(n, 0));
    dp[1][0] = 1;
    for (int mask = 1; mask < (1<<n); mask++) {
        for (int u = 1; u < n; u++) {
            if (mask&(1<<u)) {
                for (int v = 0; v < n; v++) {
                    if (mask&(1<<v) && dist[u][v] != 1e9) {
                        dp[mask][u] = (dp[mask][u]+dp[mask^(1<<u)][v]);
                    }
                }
            }
        }
    }
    ll ans = 0;
    for (int i = 1; i < n; i++) {
        if (dist[0][i] == 1)
            ans = (ans+dp[(1<<n)-1][i])%9901;
    }
    cout << (ans%2 ? ((ans+9901)/2)%9901: ans/2) << '\n';
}

int main() {
    speedup
    int tcs; cin >> tcs;
    for (int i = 1; i <= tcs; i++){
        cout << "Case " << '#' << i << ": ";
        solve();
    }
    return 0;
}
