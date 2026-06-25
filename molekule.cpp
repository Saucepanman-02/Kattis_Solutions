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
vector<int> col;

void dfs(int u){
    for (int v: g[u]){
        if (col[v] == -1){
            col[v] = 1-col[u];
            dfs(v);
        }
    }
}

int main() {
    speedup
    int n; cin >> n;
    g.resize(n);
    vector<int> deg(n, 0);
    vector<pii> e(n-1);
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        e[i] = {u, v};
        g[u].push_back(v);
        g[v].push_back(u);
        deg[u]++;
        deg[v]++;
    }
    int mx = 0, c = 0;
    for (int i = 0; i < n; i++){
        if (deg[i] > mx){
            mx = deg[i];
            c = i;
        }
    }
    col.assign(n, -1);
    col[c] = 0;
    dfs(c);
    for (int i = 0; i < n-1; i++){
        cout << 1-col[e[i].s] << endl;
    }
    return 0;
}
