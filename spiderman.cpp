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
        int n; cin >> n;
        vi a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int m = 1005;
        vector<vi> dp(n+1, vi(m+1, 1e9));
        vector<vector<char>> btrack(n+1, vector<char>(m+1, 'X'));
        dp[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (j >= a[i-1]) {
                    if (dp[i][j] > max(j, dp[i-1][j-a[i-1]])) {
                        dp[i][j] = max(j, dp[i-1][j-a[i-1]]);
                        btrack[i][j] = 'U';
                    }
                }
                if (j+a[i-1] <= m) {
                    if (dp[i][j] > max(j+a[i-1], dp[i-1][j+a[i-1]])) {
                        dp[i][j] = max(j+a[i-1], dp[i-1][j+a[i-1]]);
                        btrack[i][j] = 'D';
                    }
                }
            }
        }
        if (dp[n][0] == 1e9) {
            cout << "IMPOSSIBLE" << '\n';
        }else {
            int c = n, cur = 0;
            string st = "";
            while (c >= 1) {
                st.push_back(btrack[c][cur]);
                if (btrack[c][cur] == 'U') {
                    cur -= a[c-1];
                }else {
                    cur += a[c-1];
                }
                c--;
            }
            reverse(st.begin(), st.end());
            cout << st << '\n';
        }
    }
    return 0;
}
