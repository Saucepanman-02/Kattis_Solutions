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


int main() {
    speedup
    int tcs; cin >> tcs;
    while (tcs--) {
        int m; cin >> m;
        int k; cin >> k;
        vi c(k);
        int M = 0;
        for (int i = 0; i < k; i++) {
            cin >> c[i]; M += c[i];
        }
        M++;
        vi dp(M, 1e9);
        dp[0] = 0;
        for (int r: c) {
            for (int i = M; i >= 1; i--) {
                if (i >= r) {
                    dp[i] = min(dp[i], dp[i-r]+1);
                }
            }
        }
        for (int i = m; i < M; i++) {
            if (dp[i] != 1e9) {
                cout << i << ' ' << dp[i] << '\n';
                break;
            }
        }
    }
    return 0;
}
