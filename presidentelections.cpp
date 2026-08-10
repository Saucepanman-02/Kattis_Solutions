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

vll v, w;

int main() {
    int n; ll m = 0; cin >> n;
    v.resize(n), w.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i]; ll a, b, c; cin >> a >> b >> c;
        if (a+c <= b) {
            w[i] = 1e12;
        }else if (a > b+c) {
            w[i] = 0;
        }else {
            w[i] = (b+c-a)/2+1;
        }
        m += v[i];
    }
    vector<vll> dp(m+1, vll(n+1, 1e12));
    for (int j = 0; j <= n; j++) {
        dp[0][j] = 0;
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (v[j-1] > i) {
                dp[i][j] = dp[i][j-1];
                continue;
            }
            dp[i][j] = min(dp[i][j-1], dp[i-v[j-1]][j-1]+w[j-1]);
        }
    }
    ll ans = 1e12;
    for (int i = (m)/2+1; i <= m; i++) {
        ans = min(ans, dp[i][n]);
    }
    if (ans == 1e12) {
        cout << "impossible" << '\n';
    }else {
        cout << ans << '\n';
    }
    return 0;
}
