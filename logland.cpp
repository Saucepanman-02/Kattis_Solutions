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

const ll MOD = 1e9+7;

int main() {
    int n; cin >> n;
    vll a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vll duf(n);
    duf[0] = a[0];
    for (int i = 1; i < n; i++) {
        duf[i] = duf[i-1]/2 + a[i];
    }
    for (int i = n-1; i >= 0; i--){
        if (a[i]%2 == 0) {
            a[i] = 0;
        }else if (duf[i]-a[i] > 0) {
            a[i] = 0;
        }else {
            a[i] = 1;
        }
    }
    ll ans = 0;
    ll pow = 1;
    for (int i = 0; i < n; i++) {
        ans = (ans+pow*a[i])%MOD;
        pow = (2*pow)%MOD;
    }
    cout << ans << endl;
    return 0;
}
