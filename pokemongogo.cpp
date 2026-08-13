#include <bits/stdc++.h>

using namespace std;

#define speedup ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define usopen(file) do{freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);}while(0);
#define ll long long
#define db double
#define pii pair<int, int>
#define pdd pair<db, db>
#define vi vector<int>
#define vll vector<ll>
#define pll pair<ll, ll>
#define f first
#define s second
#define pdi pair<db, int>
#define LSOne(x) (x&(x-1))^x


map<int, string> mp;
map<int, pii> mc;
unordered_map<string, int> sh;

int dist(pii a, pii b) {
    return abs(a.f-b.f)+abs(a.s-b.s);
}


int main() {
    speedup
    int n; cin >> n;
    pii h = {0, 0};
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        pii r; cin >> r.f >> r.s;
        string st; cin >> st;
        mp[i] = st;
        mc[i] = r;
        if (sh.find(st) == sh.end()) {
            cnt++;
        }
        sh[st] = i;
    }
    vector<vll> dp((1<<n), vll(n, 1e10));
    for (int i = 0; i < n; i++) {
       dp[(1<<i)][i]  = dist(h, mc[i]);
    }
    for (int mask = 1; mask < (1<<n); mask++) {
        for (int u = 0; u < n; u++) {
            if (mask & (1<<u)) {
                for (int v = 0;  v < n; v++) {
                    if ((mask & (1<<v)) && (u != v)) {
                        dp[mask][u] = min(dp[mask][u], dp[mask^(1<<u)][v]+dist(mc[u], mc[v]));
                    }
                }
            }
        }
    }
    ll ans = 1e10;
    int fmask = 0;
    for (int mask = 1; mask < (1<<n); mask++) {
        unordered_map<string, int> rf; int cr = 0;
        for (int i = 0; i < n; i++) {
            if (mask&(1<<i) && rf.find(mp[i]) == rf.end()) {
                rf[mp[i]] = 1; cr++;
            }
        }
        if (cr == cnt) {
            for (int i = 0; i < n; i++) {
                if (mask&(1<<i)) {
                    if (dp[mask][i]+dist(mc[i], h) < ans) {
                        ans = dp[mask][i]+dist(mc[i], h); fmask = mask;
                    }
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
