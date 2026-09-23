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
    vll v(6);
    for (int i = 0; i < 6; i++) {
        cin >> v[i];
    }
    FenwickTree T(n);
    vector<FenwickTree> tr(6, T);
    string st; cin >> st;
    vi f(n+1);
    for (int i = 0; i < n; i++) {
        tr[st[i]-'1'].upd(i+1, 1);
        f[i+1] = st[i]-'1';
    }
    for (int i = 0; i < q; i++) {
        int c; cin >> c;
        if (c == 1) {
            int k, p; cin >> k >> p;
            tr[f[k]].upd(k, -1);
            tr[p-1].upd(k, 1);
            f[k] = p-1;
        }else if (c == 2) {
            int p, vl; cin >> p >> vl;
            v[p-1] = vl;
        }else {
            int l, r; cin >> l >> r;
            ll sum = 0;
            for (int j = 0; j < 6; j++) {
                sum += (tr[j].rsq(r)-tr[j].rsq(l-1))*v[j];
            }
            cout << sum << '\n';
        }
    }
    return 0;
}
