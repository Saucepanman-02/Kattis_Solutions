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
map<tuple<int, int, int>, int> mp;
map<int, tuple<int, int, int>> pm;
map<pii, int> mp1;

bool flag = false;
vector<vector<int>> fg;

void dfs(int u, int p){
    vis[u] = 1;
    for (int v: g[u]){
        if (vis[v] == -1){
            dfs(v, u);
        }else if (vis[v] == 1 && v != p){
            flag = true;
        }
    }
    vis[u] = 2;
}

void dfs1(int u, int p){
    vis[u] = 1;
    for (int v: fg[u]){
        if (vis[v] == -1){
            dfs1(v, u);
        }else if (vis[v] == 1 && v != p){
            flag = true;
        }
    }
    vis[u] = 2;
}
int main() {
    speedup
    int k; cin >> k;
    int n = 0, m = 0;
    vector<pii> e(k);
    vector<pii> fe;
    for (int i = 0; i < k; i++){
        int a, b, c; int x, y, z;
        cin >> a >> b >> c >> x >> y >> z;
        tuple<int, int, int> P = {a, b, c}, Q = {x, y, z};
        int c1, c2;
        if (mp.find(P) != mp.end()){
            c1 = mp[P];
        }else{
            c1 = n; n++;
            mp[P] = c1;
//            pm[c1] = P;
        }
        if (mp.find(Q) != mp.end()){
            c2 = mp[Q];
        }else{
            c2 = n; n++;
            mp[Q] = c2;
  //          pm[c2] = Q;
        }
        e[i] = {c1, c2};
        pii S = {a, b}, T = {x, y};
        if (mp1.find(S) != mp1.end()){
            c1 = mp1[S];
        }else{
            c1 = m; m++;
            mp1[S] = c1;
        }
        if (mp1.find(T) != mp1.end()){
            c2 = mp1[T];
        }else{
            c2 = m; m++;
            mp1[T] = c2;
        }
        if (c1 != c2)
            fe.push_back({c1, c2});
    }
    g.resize(n);
    fg.resize(m);
    for (auto &[u, v]: e){
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (auto &[u, v]: fe){
        fg[u].push_back(v);
        fg[v].push_back(u);
    }
    vis.assign(n, -1);
    for (int i = 0; i < n; i++){
        if (vis[i] == -1){
            dfs(i, -1);
        }
    }
    if (flag){
        cout << "True closed chains" << endl;
    }else{
        cout << "No true closed chains" << endl;
    }
    vis.assign(m, -1);
    flag = false;
    for (int i = 0; i < m; i++){
        if (vis[i] == -1){
            dfs1(i, -1);
        }
    }
    if (flag){
        cout << "Floor closed chains" << endl;
    }else{
        cout << "No floor closed chains" << endl;
    }
    return 0;
}
