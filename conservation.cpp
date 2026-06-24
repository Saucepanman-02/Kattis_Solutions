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

int topo(vector<int> a, int n, vi deg, int c){
    vector<bool> vis(n, false);
    deque<int> dq;
    for (int i = 0; i < n; i++){
        if (deg[i] == 0){
            if (a[i]==1){
                dq.push_front(i);
            }else{
                dq.push_back(i);
            }
        }
    }
    int ans = 0;
    int cur = c-1;
    while (!dq.empty()){
        int u;
        if (cur){
            u = dq.back(); dq.pop_back();
        }else{
            u = dq.front(); dq.pop_front();
        }
        if (vis[u]){
            continue;
        }
        vis[u] = true;
        if (!(a[u] == cur+1)){
            ans++;
            cur = a[u]-1;
        }
        for (int v: g[u]){
            deg[v]--;
            if (deg[v] == 0){
                if (a[v] == 1){
                    dq.push_front(v);
                }else{
                    dq.push_back(v);
                }
            }
        }
    }
    return ans;
}

int main() {
    speedup
    int t; cin >> t;
    while (t--){
        int n, m; cin >> n >> m;
        g.assign(n, vector<int>());
        vector<int> a(n), deg(n, 0);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        for (int i = 0; i < m; i++){
            int u, v; cin >> u >> v; u--, v--;
            g[u].push_back(v);
            deg[v]++;
        }
        int a1 = topo(a, n, deg, 1), a2 = topo(a, n, deg, 2);
        cout << min(a1, a2) << endl;
    }
    return 0;
}
