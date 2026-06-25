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
bool flag;

void dfs(int u){
    if (vis[u] == 1){
        flag = true;
        return;
    }
    if (vis[u] == 2){
        return;
    }
    vis[u] = 1;
    for (int v: g[u]){
        dfs(v);
    }
    vis[u] = 2;
}

int main() {
    speedup
    int n; cin >> n;
    map<string, int> mp;
    map<int, string> pm;
    int c = 0;
    for (int i = 0; i < n; i++){
        string s1, s2; cin >> s1 >> s2;
        int c1, c2;
        if (mp.find(s1) != mp.end()){
            c1 = mp[s1];
        }else{
            c1 = c;
            mp[s1] = c1;
            g.push_back({});
            c++;
        }
        if (mp.find(s2) != mp.end()){
            c2 = mp[s2];
        }else{
            c2 = c;
            mp[s2] = c2;
            g.push_back({});
            c++;
        }
        g[c1].push_back(c2);
    }
    string st;
    while (cin >> st){
        vis.assign(c, -1);
        flag = false;
        if (mp.find(st) != mp.end()) {
            dfs(mp[st]);
        }
        cout << st << ' ' << (flag? "safe": "trapped") << endl;
    }
    return 0;
}
