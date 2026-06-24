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
    int n, m; cin >> n >> m;
    g.assign(n, vector<int>());
    vis.assign(n, false);
    vi deg(n, 0);
    for (int i = 0; i < m; i++){
        int u, v; cin >> u >> v;u--, v--;
        g[u].push_back(v);
        deg[v]++;
    }
    queue<int> q;
    for (int i = 0; i < n; i++){
        if (!deg[i]){
            q.push(i);
        }
    }
    vi ans;
    while (!q.empty()){
        int u = q.front(); q.pop();
        if (vis[u])
            continue;
        vis[u] = true;
        ans.push_back(u);
        for (int v: g[u]){
            deg[v]--;
            if (!deg[v]){
                q.push(v);
            }
        }
    }
    if (ans.size() != n){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    for (int c: ans){
        cout << c+1 << '\n';
    }
    return 0;
}
