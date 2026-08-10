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

vector<vi> dp;
vi c;
vector<vi> unq;

int memo(int st, int k) {
    if (st == 0) {
        return 1;
    }
    if (dp[st][k] != -1) {
        return dp[st][k]; //0- Not Possible, 1- Unique, >= 2 - Ambiguous
    }
    if (k  == 0) {
        return 0;
    }
    int cnt = 0;
    for (int i = st; i >= 0; i -= c[k-1]) {
        cnt += memo(i, k-1);
        if (cnt >= 2) {
            return (dp[st][k] = 2);
        }
    }
    return (dp[st][k] = cnt);
}

void btrack(int st, int k) {
    if (k == 0) {
        return;
    }
    for (int i  = st; i >= 0; i -= c[k-1]) {
        if (memo(i, k-1) == 1) {
            btrack(i, k-1);
            for (int j = 0; j < (st-i)/c[k-1]; j++) {
                cout << k << ' ';
            }
            return;
        }
    }
}
int main() {
    int n; cin >> n;
    c.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    int m; cin >> m;
    vi ord(m);
    int mx = 0;
    for (int i = 0; i < m; i++) {
        cin >> ord[i];
        mx = max(ord[i], mx);
    }
    dp.resize(mx+1,  vi(n+1, -1));
    for (int i = 0; i < m; i++) {
        if (memo(ord[i], n) == 1) {
            btrack(ord[i], n);
            cout << '\n';
        }else if (memo(ord[i], n) >= 2) {
            cout << "Ambiguous" << '\n';
        }else {
            cout << "Impossible" << '\n';
        }
    }
    return 0;
}
