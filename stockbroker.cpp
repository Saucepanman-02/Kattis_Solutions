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
    int n; cin >> n;
    vll a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    ll mon = 100;
    for (int i = 1; i < n; i++) {
        if (a[i] > a[i-1]) {
            ll stocks = min(mon/a[i-1], (ll)1e5);
            mon += (a[i]-a[i-1])*stocks;
        }
    }
    cout << mon << endl;
    return 0;
}
