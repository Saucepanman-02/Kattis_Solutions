#include <bits/stdc++.h>

using namespace std;

#define speedup ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define usopen(filename) do{freopen(filename".in", "r", stdin); freopen(filename".out", "w", stdout);}while(0);
#define f first
#define s second
#define ll long long
#define db double
#define pii pair<int, int>
#define pdd pair<db, db>
#define vi vector<int>
#define vll vector<ll>

vector<vector<pii>> g;

int main() {
    speedup
    int n; cin >> n;
    g.assign(n, vector<pii>());
    vector<bool> vis(n, false);
    vector<int> tresh(n, 0), ct(n, 0);
    for (int i = 0; i < n; i++){
        int k; cin >> tresh[i] >> k;
        for (int j = 0; j < k; j++){
            int u, st; cin >> u >> st; u--;
            g[u].push_back({i, st});
            ct[i] += st;
        }
    }
    queue<int> q;
    q.push(0);
    while (!q.empty()){
        int u = q.front(); q.pop();
        if (vis[u]){
            continue;
        }
        vis[u] = true;
        for (auto &[v, w]: g[u]){
            ct[v] -= w;
            if (ct[v] < tresh[v]){
                q.push(v);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++){
        ans += (!vis[i]);
    }
    cout << ans << endl;
    return 0;
}
