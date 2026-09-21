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
#define floor(n, r) (ll)(n/r);
#define pil pair<int, ll>
#define l(p) (p << 1)
#define r(p) ((p<<1)+1)

class SegmentTree {
private:
    int n;
    vi A, st1, st2, lazy;
    int con1(int a, int b) {
        if (a == -1) return b;
        if (b == -1) return a;
        return min(a, b);
    }
    int con2(int a, int b) {
        return max(a, b);
    }
    void build(int p, int L, int R) {
        if (L == R) {
            st1[p] = A[L];
            st2[p] = A[L];
            return;
        }
        int m = (L+R)/2;
        build(l(p), L, m);
        build(r(p), m+1, R);
        st1[p] = con1(st1[l(p)], st1[r(p)]);
        st2[p] = con2(st2[l(p)], st2[r(p)]);
    }
    void prop(int p, int L, int R) {
        if (lazy[p] != 0) {
            st1[p] += lazy[p];
            st2[p] += lazy[p];
            if (L != R) {
                lazy[l(p)] += lazy[p];
                lazy[r(p)] += lazy[p];
            }else {
                A[L] += lazy[p];
            }
            lazy[p] = 0;
        }
    }
    int query(int p, int L, int R, int idx) {
        prop(p, L, R);
        if (L == R && R == idx) {
            return st1[p];
        }
        int m = (L+R)/2;
        if (idx <= m) {
            return query(l(p), L, m, idx);
        }else {
            return query(r(p), m+1, R, idx);
        }
    }
    void update (int p, int L, int R, int c) {
        prop(p, L, R);
        if (L > R)
            return;
        if (st1[p] > c) {
            return;
        }
        if (st2[p] < c) {
            lazy[p]++;
            prop(p, L, R);
            return;
        }
        int m = (L+R)/2;
        update(l(p), L, m, c);
        update(r(p), m+1, R, c);
        prop(l(p), L, m);
        prop(r(p), m+1, R);
        st1[p] = con1(st1[l(p)], st1[r(p)]);
        st2[p] = con2(st2[l(p)], st2[r(p)]);
        return;
    }
    void set(int p, int L, int R, int idx) {
        prop(p, L, R);
        if (L == R && R == idx) {
            st1[p] = st2[p] = -1;
            return;
        }
        int m = (L+R)/2;
        if (idx <= m) {
            set(l(p), L, m, idx);
        }else {
            set(r(p), m+1, R, idx);
        }
    }
public:
    SegmentTree(int sz): n(sz), st1(4*n), st2(4*n), lazy(4*n, 0) {}

    SegmentTree(const vi &v): SegmentTree(v.size()) {
        A = v;
        build(1, 0, n-1);
    }
    void upd(int val) {
        update(1, 0, n-1, val);
    }
    int qur(int i) {
        return query(1, 0, n-1, i);
    }
    void set(int idx) {
        set(1, 0, n-1, idx);
    }
};

int main() {
    speedup
    int t; cin >> t;
    while (t--) {
        int n, r; cin >> n >> r;
        vi a(n);
        for (int i = 1; i <= n; i++) {
            a[i-1] = i-1;
        }
        SegmentTree T(a);
        for (int i = 0; i < r; i++) {
            int c; cin >> c;
            c--;
            int cur = T.qur(c);
            T.set(c);
            T.upd(cur);
            cout << cur << ' ';
        }
        cout << '\n';
    }
    return 0;
}
