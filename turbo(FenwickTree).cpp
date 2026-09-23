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
#define floor(n, r) (ll)(n/r)
#define pil pair<int, ll>

#define LSOne(x) (x&(-x))

class FenwickTree {
private:
    int m;
    vll ft;
public:
    FenwickTree(int sz) {ft.assign(sz+1, 0); m = sz;}

    void build(const vll &f) {
        m = f.size()-1;
        int sz = f.size()-1;
        ft.assign(sz+1, 0);
        for (int i = 1; i <= sz; i++) {
            ft[i] += f[i];
            if (i+LSOne(i) <= m)
                ft[i+LSOne(i)] += ft[i];
        }
    }
    FenwickTree(const vll &f) {build(f);}

    void upd(int i, int c) {
        for (; i <= m; i += LSOne(i)) {
            ft[i] += c;
        }
    }
    ll rsq(int i) {
        ll sum = 0;
        for (; i > 0; i -= LSOne(i)) {
            sum += ft[i];
        }
        return sum;
    }
};

int main() {
    speedup
    int n; cin >> n;
    vi a(n+1);
    for (int i = 0; i < n; i++) {
        int c; cin >> c;
        a[c] = i+1;
    }
    vll f(n+1, 1);
    f[0] = 0;
    FenwickTree T(f);
    ll ans = 0;
    for (int i = 1; i <= n-i+1; i++) {
        cout << (a[i] > 1? T.rsq(a[i]-1): 0) << '\n';
        T.upd(a[i], -1);
        if (i != n-i+1) {
            cout << T.rsq(n) - T.rsq(a[n-i+1]) << '\n';
            T.upd(a[n-i+1], -1);
        }
    }
    return 0;
}
