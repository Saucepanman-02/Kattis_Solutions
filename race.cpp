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



int main() {
    speedup
    int n; ll T; cin >> n >> T;
    vi p(n), t(n), d(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i] >> t[i] >> d[i];
    }
    vector<vi> dist(n+2, vi(n+2));
    for (int i = 0; i < n+2; i++) {
        for (int j = 0; j < n+2; j++) {
            cin >> dist[i][j];
        }
    }
    vector<vi> dp((1<<n), vi(n, 1e9));
    for (int i = 0; i < n; i++) {
        if (dist[n][i]+t[i] <= d[i] || d[i] == -1) {
            dp[(1<<i)][i] = dist[n][i]+t[i];
        }
    }
    for (int mask = 1; mask < (1<<n); mask++) {
        for (int u = 0; u < n; u++) {
            if (mask&(1<<u)) {
                for (int v = 0; v < n; v++) {
                    if (mask&(1<<v) && u != v) {
                        if (dp[mask^(1<<u)][v]+dist[v][u]+t[u] <= d[u] || d[u] == -1) {
                            if (dp[mask^(1<<u)][v]+dist[v][u]+t[u] < dp[mask][u]) {
                                dp[mask][u] = dp[mask^(1<<u)][v]+dist[v][u]+t[u];
                            }
                        }
                    }
                }
            }
        }
    }
    int fmask = -1; ll mp = -1;
    for (int mask = 1; mask < (1<<n); mask++) {
        for (int i = 0; i < n; i++) {
            if (dp[mask][i]+dist[i][n+1] <= T) {
                ll cp = 0;
                for (int j = 0; j < n; j++) {
                    if ((1<<j)&mask) {
                        cp += p[j];
                    }
                }
                if (cp > mp) {
                    mp = cp;
                    fmask = mask;
                }
            }
        }
    }
    if (mp != -1) {
        cout << mp << endl;
        for (int i = 0; i < n; i++) {
            if ((1<<i)&fmask) {
                cout << i+1 << ' ';
            }
        }
        cout << '\n';
    }else {
        cout << 0 << '\n';
    }
    return 0;
}
