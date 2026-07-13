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


int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        priority_queue<ll> pq;
        for (int i = 0; i < n; i++) {
            ll c; cin >> c;
            pq.push(-c);
        }
        ll ans = 0;
        while (pq.size() > 1) {
            ll a = pq.top(); pq.pop();
            ll b = pq.top(); pq.pop();
            ans -= (a+b);
            pq.push(a+b);
        }
        cout << ans << '\n';
    }

    return 0;
}
