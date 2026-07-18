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

vector<vi> g;
vi mar;
vi tr;
int src;
int ans;

void dfs(int u, int p) {
    tr[u] = mar[u];
    for (int v: g[u]) {
        if (v == p) {
            continue;
        }
        dfs(v, u);
        tr[u] += tr[v];
    }
    ans += abs(tr[u]);
}
int n;

void solve() {
    g.assign(n, vi());
    mar.assign(n, 0);
    tr.assign(n, 0);
    for (int i = 0; i < n; i++) {
        int u; cin >> u; u--;
        int m; cin >> m; mar[u] = m-1;
        int d; cin >> d;
        for (int j = 0; j < d; j++) {
            int r; cin >> r; r--;
            g[u].push_back(r);
            g[r].push_back(u);
        }
    }
    ans = 0;
    dfs(0, -1);
    cout << ans << endl;
}

int main() {
    while (cin >> n && n) {
        solve();
    }
    return 0;
}
