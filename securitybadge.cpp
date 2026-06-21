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
int n, ln, b;
int st, de;

vector<vector<pair<int, pii>>> g;
vector<bool> vis;

void dfs(int u, int d){
    if (u == de){
        vis[de] = true;
        return;
    }
    if (vis[u]){
        return;
    }
    vis[u] = true;
    for (auto &[v, pr]: g[u]){
        if (d >= pr.f && d <= pr.s){
            dfs(v, d);
        }
    }
}


int main() {
    cin >> n >> ln >> b;
    cin >> st >> de;
    g.resize(n);

    vi crit  = {1, b};
    for (int i = 0; i < ln; i++){
        int u, v, x, y; cin >> u >> v >> x >> y;
        u--, v--;
        g[u].push_back({v, {x, y}});
        crit.push_back(x);
        crit.push_back(y);
    }
    st--, de--;
    sort(crit.begin(), crit.end());
    crit.erase(unique(crit.begin(), crit.end()), crit.end());
    int sz = crit.size();
    int ans = 0;
    vector<bool> flag(sz, false);
    for (int i = 0; i < sz; i++){
        vis.assign(n, false);
        int t = crit[i];
        dfs(st, t);
        if (vis[de])
            flag[i] = true;
    }
    //vector<pii> unflag;
    for (int i = 0; i < sz-1; i++){
        if (flag[i] && flag[i+1]) {
            /*
            if (unflag.empty()){
                unflag.push_back({crit[i], crit[i+1]});
            }else{
                if (flag[i-1]){
                    unflag.back().second = crit[i+1];
                }else{
                    unflag.push_back({crit[i], crit[i+1]});
                }
            }*/
            int md = (crit[i+1]+crit[i])/2;
            vis.assign(n, false);
            dfs(st, md);
            if (vis[de]) {
                ans += crit[i + 1] - crit[i];
            }else{
                ans++;
            }
        }else if (flag[i] && !flag[i+1]){
            ans++;
        }
    }
    if (flag[sz-1]){
        ans++;
    }
    cout << ans << endl;
    return 0;
}
