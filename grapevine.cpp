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

int main() {
    speedup
    int n, m, d; cin >> n >> m >> d;
    map<string, int> mp;
    vector<int> a(n);
    g.resize(n);
    for (int i = 0; i < n; i++){
        string st; cin >> st;
        cin >> a[i];
        mp[st] = i;
    }
    for (int i = 0; i < m; i++){
        string s1, s2; cin >> s1 >> s2;
        g[mp[s1]].push_back(mp[s2]);
        g[mp[s2]].push_back(mp[s1]);
    }
    vector<int> cur(n, 0);
    string st; cin >> st;
    queue<int> q;
    q.push(mp[st]);
    vector<int> time(n, -1);
    vector<bool> heard(n, false);
    time[mp[st]] = 0;
    heard[mp[st]] = true;
    while (!q.empty()){
        int u = q.front(); q.pop();
        for (int v: g[u]){
            cur[v]++;
            if (time[u] < d) {
                heard[v] = true;
            }
            if (time[v] == -1 && cur[v] >= a[v]){
                q.push(v);
                time[v] = time[u]+1;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++){
        if (heard[i]){
            ans++;
        }
    }
    cout << ans-1 << endl;
    return 0;
}
