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

vector<vll> dp;
const int MOD = 1001113;

ll memo(int n, int v) {
    if (v >= n) {
        return 0;
    }
    if (v == 0 && n) {
        return 1;
    }
    if (dp[n][v] != -1) {
        return dp[n][v];
    }
    ll cur = ((memo(n-1, v)*(v+1))%MOD+(memo(n-1, v-1)*(n-(v)))%MOD)%MOD;
    return (dp[n][v] = cur);
}

int main() {
    speedup
    int tcs; cin >> tcs;
    dp.assign(101, vll(101, -1));
    while (tcs--) {
        int rf, n, v;
        cin >> rf >> n >> v;
        cout << rf << ' ' << memo(n, v) << '\n';
    }
    return 0;
}
