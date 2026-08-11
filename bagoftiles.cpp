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

vector<vll> memo;

ll nCr(int n, int r) {
    if (n < 0) {
        return 0;
    }
    if (r == 0) {
        return 1;
    }
    if (n == r) {
        return 1;
    }
    if (n < r) {
        return 0;
    }
    if (memo[n][r] != -1) {
        return memo[n][r];
    }
    return (memo[n][r] = nCr(n-1, r-1)+nCr(n-1, r));
}
int main() {
    speedup
    int tcs; cin >> tcs;
    memo.assign(35+1, vll(35+1, -1));
    for (int tc = 0; tc < tcs; tc++){
        int m; cin >> m;
        vi c(m);
        for (int i = 0; i < m; i++) {
            cin >> c[i];
        }
        int n, t; cin >> n >> t;
        vector<vll> dp(t + 1, vll(n + 1, 0));
        dp[0][0] = 1;

        for (int x : c) {
            for (int i = t; i >= x; --i) {
                for (int r = n; r >= 1; --r) {
                    dp[i][r] += dp[i - x][r - 1];
                }
            }
        }

        cout << "Game " << tc+1 << " -- " <<  dp[t][n] << " : " << nCr(m, n)-dp[t][n] << '\n';
    }
    return 0;
}
