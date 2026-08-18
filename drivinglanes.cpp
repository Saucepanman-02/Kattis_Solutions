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
#define ceil(n, r) (ll)((n+r-1)/r)
#define floor(n, r) (ll)(n/r);


int main() {
    speedup
    int n, m; cin >> n >> m;
    int k, r; cin >> k >> r;
    vi l(n);
    for (int i = 0; i < n; i++) {
        cin >> l[i];
    }
    vector<pii> cur(n-1);
    for (int i = 0; i < n-1; i++) {
        cin >> cur[i].f >> cur[i].s;
    }
    vector<vi> dp(2*n, vi(m, 1e9));
    dp[0][0] = 0;
    for (int i = 1; i < 2*n; i++) {
        for (int j = 0; j < m; j++) {
            if (i&1) { //Highway
                int hw = (i-1)/2;
                int rng = (l[hw])/k;
                for (int st = 0; st <= rng; st++) {
                    if (j+st < m) {
                        dp[i][j] = min(dp[i][j], dp[i-1][j+st]+l[hw]+st*r);
                    }
                    if (j-st >= 0) {
                        dp[i][j] = min(dp[i][j], dp[i-1][j-st]+l[hw]+st*r);
                    }
                }
            }else { //Curve
                int cr = i/2-1;
                dp[i][j] = min(dp[i][j], cur[cr].f+cur[cr].s*(j+1)+dp[i-1][j]);
            }
        }
    }
    cout << dp[2*n-1][0] << '\n';
    return 0;
}
