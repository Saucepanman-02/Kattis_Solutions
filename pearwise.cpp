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


int n, m;
vector<vi> g;
vector<bool> vis;

int cnt = 0;

void dfs(int u){
    if (vis[u]){
        return;
    }
    cnt++;
    vis[u] = true;
    for (int v: g[u]){
        dfs(v);
    }
}
int main() {
    cin >> n >> m;
    g.resize(n);
    vector<pair<int, string>> e(m);
    for (int i = 0; i < m; i++){
        cin >> e[i].f >> e[i].s;
    }
    for (int i = 0; i < n; i++){
        for (int j = i+1;  j < n; j++){
            int cnt1 = 0, cnt2 = 0;
            for (int k = 0; k < m; k++){
                int c1, c2;
                for (int r = 0; r < n; r++){
                    if (e[k].s[r] == char(i+'A')){
                        c1 = r;
                    }
                    if (e[k].s[r] == char(j+'A')){
                        c2 = r;
                    }
                }
                if (c1 < c2){
                    cnt1 += e[k].f;
                }else{
                    cnt2 += e[k].f;
                }
            }
            if (cnt1 > cnt2){
                g[i].push_back(j);
            }else{
                g[j].push_back(i);
            }
        }
    }
    for (int i = 0; i < n; i++){
        vis.assign(n, false);
        cnt = 0;
        dfs(i);
        cout << char(i+'A') << ": ";
        if (cnt == n){
            cout << "can win";
        }else{
            cout << "can't win";
        }
        if (i != n-1) {
            cout << '\n';
        }
    }
    
    return 0;
}
