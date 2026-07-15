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
    ll n,k; cin >> n >> k;
    priority_queue<pair<ll, ll>> pq;
    vll a(n);
    for (ll i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < min(n, k); i++) {
        pq.push({-a[i], i});
    }
    ll cnt = 0;
    ll ans = 0;
    vector<bool> vis(k, false);
    while (cnt < n) {
        pll u = pq.top(); pq.pop();
        if (vis[u.s]) {
            cnt += 4;
        }else {
            cnt += 5;
            vis[u.s] = true;
        }
        ans = max(ans, -u.f);
        u.f -= 2*a[u.s];
        pq.push(u);
    }
    cout << ans << endl;
    return 0;
}
