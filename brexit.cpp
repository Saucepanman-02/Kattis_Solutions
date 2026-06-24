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

vector<vi> g;
vector<bool> vis;

int main() {
    speedup
    int n, m, p, x; cin >> n >> m >> p >> x;
    g.resize(n), vis.resize(n);
    vi deg(n, 0);
    for (int i = 0; i < m; i++){
        int u,v; cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
        deg[u]++, deg[v]++;
    }
    queue<int> q;
    vi deg_org = deg;
    x--;
    for (int v: g[x]){
        deg[v]--;
        if (deg[v] <= deg_org[v]/2){
            q.push(v);
        }
    }
    vis[x] = true;
    while (!q.empty()){
        int u = q.front(); q.pop();
        if (vis[u]){
            continue;
        }
        vis[u] = true;
        for (int v: g[u]){
            deg[v]--;
            if (deg[v] <= deg_org[v]/2 && !vis[v]){
                q.push(v);
            }
        }
    }
    cout << (vis[p-1]?"leave": "stay") << endl;
    return 0;
}
