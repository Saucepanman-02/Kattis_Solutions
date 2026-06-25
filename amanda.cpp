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
vector<int> col;
vector<bool> vis;
bool flag = true;
int cur = 0;
int cnt;

void dfs(int u){
    if (vis[u]){
        return;
    }
    vis[u] = true;
    cnt++;
    cur += col[u];
    for (auto &[v, w]: g[u]){
        if (col[v] == -1){
            col[v] = w-col[u];
            if (col[v] >= 2 || col[v] < 0){
                flag = false;
            }
            dfs(v);
        }else if (col[u]+col[v] != w){
            flag = false;
        }
    }
}

int main() {
    speedup
    int n, m; cin >> n >> m;
    g.resize(n);
    col.assign(n, -1);
    vector<bool> start(n, false);
    int u, v, w;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        u--, v--;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
        if (w == 2){
            if ((col[u] == -1 || col[u] == 1)  && (col[v] == -1 || col[v] == 1)) {
                start[u] = true;
                start[v] = true;
                col[u] = col[v] = 1;
            }else{
                cout << "impossible" << endl;
                return 0;
            }
        }else if (w == 0){
            if ((col[u] == -1 || col[u] == 0) && (col[v] == -1 || col[v] == 0)) {
                start[u] = true;
                start[v] = true;
                col[u] = col[v] = 0;
            }else{
                cout << "impossible" << endl;
                return 0;
            }
        }
    }
    int ans = 0;
    vis.assign(n, false);
    for (int i = 0; i < n; i++){
        if (start[i] && !vis[i]){
            cur = 0;
            dfs(i);
            if (!flag){
                cout << "impossible" << endl;
                return 0;
            }
            ans += cur;
        }
    }
    for (int i = 0; i < n; i++){
        if (col[i] == -1){
          cur = cnt = 0;
          col[i] = 0;
          dfs(i);
            if (!flag){
                cout << "impossible" << endl;
                return 0;
            }
          ans += min(cur, cnt-cur);
        }
    }
    if (!flag){
        cout << "impossible" << endl;
    }else{
        cout << ans << endl;
    }
    return 0;
}
