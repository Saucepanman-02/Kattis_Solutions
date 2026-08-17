
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

ll n, r, p;

vll dp;

ll memo(int c) {
    if (dp[c] != 1e10) {
        return dp[c];
    }
    ll cur = (c-1)*p+r;
    ll N = c-1;
    for (int i = c-1; i >= 2; ) {
        ll t = N / i;                 
        int lo = (int)(N / (t+1)) + 1; 
        cur = min(cur, memo(lo)+t*p+r); 
        i = lo - 1;                    
    }
    return (dp[c] = cur);
}

int main() {
    speedup
    cin >> n >> r >> p;
    dp.assign(n+1, 1e10);
    dp[1] = dp[0] = 0;
    cout << memo(n) << '\n';
    return 0;
}
