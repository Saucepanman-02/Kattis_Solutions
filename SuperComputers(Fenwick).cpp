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
    int n, q; cin >> n >> q;
    FenwickTree T(n);
    vi f(n+1);

    for (int i = 0; i < q; i++) {
        char c; cin >> c;
        if (c == 'F') {
            int k; cin >> k;
            if (f[k]) {
                T.upd(k, -1);
            }else {
                T.upd(k, 1);
            }
            f[k] = 1-f[k];
        }else {
            int l, r; cin >> l >> r;
            cout << T.rsq(r) - (l > 0? T.rsq(l-1): 0) << '\n';
        }
    }
    return 0;
}
