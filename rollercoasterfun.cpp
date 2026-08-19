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
    int n; cin >> n;
    int T = 25000;
    vector<ll> dp(T+1, -1);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        ll a, b, t; cin >> a >> b >> t;
        if (b == 0) {
            if (a > 0) {
                for (int j = t; j <= T; j++) {
                    if (dp[j-t] != -1) {
                        dp[j] = max(dp[j-t]+a, dp[j]);
                    }
                }
            }
        }else {
            for (int k = 1; ;k++) {
                if (a-(k-1)*(k-1)*b <= 0) {
                    break;
                }
                ll v = a-(k-1)*(k-1)*b;
                for (int j = T; j >= t; j--) {
                    if (dp[j-t] != -1) {
                        dp[j] = max(dp[j], dp[j-t]+v);
                    }
                }
            }
        }
    }
    for (int i = 1; i <= T; i++) {
        dp[i] = max(dp[i-1], dp[i]);
    }
    int q; cin >> q;
    for (int i = 0; i < q; i++) {
        int t; cin >> t;
        cout << dp[t] << '\n';
    }
    return 0;
}
