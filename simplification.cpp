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

struct P {
    int x, y;
};

vector<P> a;

long long area(const P& a, const P& b, const P& c) {
    return abs(1LL * a.x * (b.y - c.y)
         + 1LL * b.x * (c.y - a.y)
         + 1LL * c.x * (a.y - b.y));
}

int main() {
    speedup
    int n, m; cin >> n >> m;
    a.resize(n+1);
    set<int> st;
    for (int i = 0; i <= n; i++) {
        cin >> a[i].x >> a[i].y;
        st.insert(i);
    }
    multiset<pair<ll, int>> pq;
    vi arl(n);
    for (int i = 1; i < n; i++) {
        pq.insert({area(a[i-1], a[i], a[i+1]), i});
        arl[i] = area(a[i-1], a[i], a[i+1]);
    }
    int cur = n;
    while (cur > m) {
        cur--;
        pair<ll, int> u = *pq.begin(); pq.erase(pq.begin());
        auto it1 = st.find(u.s); it1--;
        auto it2 = st.find(u.s); it2++;
        cout << u.s << '\n';
        int x = *it1, y = *it2;
        if (x >= 1) {
            pq.erase({arl[x], x});
            it1--; int z = *it1;
            arl[x] = area(a[z], a[x], a[y]);
            pq.insert({area(a[z], a[x], a[y]), x});
        }
        if (y < n) {
            pq.erase({arl[y], y});
            it2++;
            int z = *it2;
            arl[y] = area(a[x], a[y], a[z]);
            pq.insert({arl[y], y});
        }
        st.erase(st.find(u.s));
    }

    return 0;
}
