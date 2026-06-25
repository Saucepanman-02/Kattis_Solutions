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

vector<vector<int>> g;
vector<int> vis;

void dfs(int u){
    for (int v: g[u]){
        if (vis[v] == -1){
            vis[v] = 1-vis[u];
            dfs(v);
        }
    }
}

int main() {
    speedup
    int n, m; cin >> n >> m;
    g.resize(n);
    vis.assign(n, -1);
    for (int i = 0; i < m; i++){
        int u, v; cin >> u >> v; u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 0; i < n; i++){
        if (g[i].empty()){
            cout << "Impossible" << endl;
            return 0;
        }
    }
    for (int i = 0; i < n; i++){
        if (vis[i] == -1){
            vis[i] = 0;
            dfs(i);
        }
    }
    for (int i = 0; i < n; i++){
        cout << (vis[i]? "pub": "house");
        if (i != n-1){
            cout << ' ';
        }
    }
    cout << endl;
    return 0;
}
