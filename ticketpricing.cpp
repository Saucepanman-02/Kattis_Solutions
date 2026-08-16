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


vi a;
vector<vll> p;
vector<vll> st;
vector<vll> memo;
ll pr = 0;
int n, w;

ll dp(int fr, int wk) {
    if (fr == 0) {
        return 0;
    }
    if (wk > w) {
        return 0;
    }
    if (memo[fr][wk] != -1) {
        return memo[fr][wk];
    }
    int sz = p[wk].size();
    ll ans = -1e12;
    ll pr0 = 0;
    for (int i = 0; i < sz; i++) {
        if (fr >= st[wk][i]) {
            if (ans < st[wk][i]*p[wk][i]+dp(fr-st[wk][i], wk+1)){
                ans = st[wk][i]*p[wk][i]+dp(fr-st[wk][i], wk+1);
                pr0 = p[wk][i];
            }
        }else {
            if (ans < fr*p[wk][i]) {
                ans = fr*p[wk][i];
                pr0 = p[wk][i];
            }
        }
    }
    if (wk == 0) {
        pr = pr0;
    }
    return (memo[fr][wk] = ans);
}
int main() {
    speedup
    cin >> n >> w;
    memo.assign(n+1, vll(w+1, -1));
    p.resize(w+1);
    st.resize(w+1);
    for (int i = 0; i <= w; i++) {
        int r; cin >> r;
        p[i].resize(r);
        st[i].resize(r);
        for (int j = 0; j < r; j++) {
            cin >> p[i][j];
        }
        for (int j = 0; j < r; j++) {
            cin >> st[i][j];
        }
    }
    cout << dp(n, 0) << '\n';
    cout << pr << '\n';
    return 0;
}
