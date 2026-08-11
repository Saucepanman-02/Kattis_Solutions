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
    int n; cin >> n;
    vi c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    int m =  c[n-1]+c[n-2];
    vector<int> dp(m+1, 1e9);
    //vi p(m+1, -1);
    vi gr(m+1, 1e9);
    dp[0] = 0;
    gr[0] = 0;
    for (int r: c) {
        for (int i = 1; i <= m; i++) {
            if (r <= i) {
                dp[i] = min(dp[i], dp[i-r]+1);
            }
            gr[i] = min((int)1e9, gr[i%r]+(i-i%r)/r);
        }
    }
    for (int i = 1; i <= m; i++) {
        if (dp[i] != gr[i]) {
            cout << "non-canonical" << '\n';
            return 0;
        }
    }
    cout << "canonical" << '\n';
    return 0;
}
