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


int n, m;

vector<vi> dist;

int main() {
    speedup
    cin >> n >> m;
    dist.resize(n);
    for (int i = 0; i < n; i++) {
        int r; cin >> r;
        dist[i].assign(10001, 0);
        for (int j = 0; j < r; j++) {
            int u; cin >> u;
            dist[i][u] = 1;
        }
    }
    vi a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    vector<vi> dp(n, vi(m, 1e9));
    for (int i = 0; i < n; i++) {
        if (dist[i][a[0]]) {
            dp[i][0] = 0;
        }
    }
    for (int j = 1; j < m; j++) {
        for (int i = 0; i < n; i++) {
            if (dist[i][a[j]]) {
                for (int k = 0; k < n; k++) {
                    if (dist[k][a[j-1]]) {
                        dp[i][j] = min(dp[i][j], dp[k][j-1]+(k != i));
                    }
                }
            }
        }
    }
    cout << dp[n-1][m-1] << '\n';
    return 0;
}
