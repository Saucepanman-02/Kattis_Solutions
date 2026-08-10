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

int m, n;
vi v, w;
vector<vi> dp;

int memo(int st, int k) {
    if (k <= 0) {
        return 0;
    }
    if (dp[st][k] != -1) {
        return dp[st][k];
    }
    return (dp[st][k] = max(memo(st, k-1), (st >= w[k-1] ? memo(st-w[k-1], k-1)+v[k-1]: 0)));
}

vi ans;

void btrack(int st, int k) {
    if (k <= 0) {
        return;
    }
    if (st < w[k-1]) {
        btrack(st, k-1);
        return;
    }
    if (dp[st][k-1] >= dp[st-w[k-1]][k-1]+v[k-1]) {
        btrack(st, k-1);
    }else {
        ans.push_back(k-1);
        btrack(st-w[k-1], k-1);
    }
}

int main() {
    while (cin >> m >> n) {
        v.resize(n), w.resize(n);
        dp.assign(m+1, vi(n+1, -1));
        for (int i = 0; i < n; i++) {
            cin >> v[i] >> w[i];
        }
        memo(m, n);
        btrack(m, n); cout << ans.size() << '\n';
        for (int u: ans) {
            cout << u << ' ';
        }
        cout << '\n';
        ans.clear();
    }
    
    return 0;
}
