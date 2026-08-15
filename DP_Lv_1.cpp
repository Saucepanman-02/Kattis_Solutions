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

int n;
vi a;


int main() {
    speedup
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vi> dp(n+1, vi(n+1, 1e9));
    dp[1][0] = 0;
    for (int l = 1; l <= n; l++) {
        for (int i = n; i >= 1; i--) {
            if (i-l > 0) {
                dp[i][l] = min(dp[i][l], dp[i-l][l-1]+a[i-1]);
            }
            if (i+l < n) {
                dp[i][l] = min(dp[i][l], dp[i+l][l]+a[i-1]);
            }
        }
    }
    int ans = 1e9;
    for (int i = 0; i <= n; i++) {
        ans = min(ans, dp[n][i]);
    }
    cout << ans << '\n';
    return 0;
}
