#include <bits/stdc++.h>

using namespace std;

#define speedup ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define usopen(filename) do{freopen(filename".in", "r", stdin); freopen(filename".out", "w", stdout);}while(0);
#define f first
//#define s second
#define ll long long
#define db double
#define pii pair<int, int>
#define pdd pair<db, db>
#define vi vector<int>
#define vll vector<ll>

vector<vi> g(1010);
map<int, int> m;
vector<bool> vis(1010);

bool flag;

void dfs1(int u){
    if (u == 0){
        flag = true;
        return;
    }
    if (flag){
        return;
    }
    if (vis[u]){
        return;
    }
    vis[u] = true;
    for (int &v: g[u]){
        dfs1(v);
    }
}

void dfs(int u){
    if (vis[u]){
        return;
    }
    vis[u] = true;
    for (int &v: g[u]){
        dfs(v);
    }
}

int main() {
    int n; cin >> n;
    vi street;
    for (int i = 0; i < n; i++){
        int id; cin >> id;
        street.push_back(id);
        m[id] = i;
        int c; cin >> c;
        for (int it = 0; it < c; it++){
            int r; cin >> r;
            g[id].push_back(r);
        }
    }
    vi trapped;
    for (int i: street){
        vis.assign(1010, false);
        flag = false;
        dfs1(i);
        if (!flag){
            trapped.push_back(i);
        }
    }
    sort(trapped.begin(), trapped.end(), [](int &a, int &b){
       return m[a] < m[b];
    });
    vi unrech;
    vis.assign(1010, false);
    dfs(0);
    for (int c: street){
        if (!vis[c]){
            unrech.push_back(c);
        }
    }
    sort(unrech.begin(), unrech.end(), [](int &a, int &b){
        return m[a] < m[b];
    });
    if (trapped.empty() && unrech.empty()){
        cout << "NO PROBLEMS" << endl;
        return 0;
    }
    for (int c: trapped){
        cout << "TRAPPED " << c << '\n';
    }
    for (int c: unrech){
        cout << "UNREACHABLE " << c << '\n';
    }
    return 0;
}
