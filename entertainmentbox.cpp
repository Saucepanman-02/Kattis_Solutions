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

struct E {
    int st, ed;
};
bool cmp(E &a, E &b) {
    if (a.ed == b.ed) {
        return a.st > b.st;
    }
    return a.ed < b.ed;
}
multiset<int> pq;
vector<E> a;

int main() {
    speedup
    int n, k; cin >> n >> k;
    a.resize(n);
    for (E &r: a) {
        cin >> r.st >> r.ed;
    }
    sort(a.begin(), a.end(), cmp);

    int ans = 0;
    for (E &r: a) {
        auto it = pq.upper_bound(r.st);
        if (it != pq.begin()) {
            it--;
            pq.erase(it);
            pq.insert(r.ed);
            ans++;
        }else {
            if (pq.size() < k) {
                pq.insert(r.ed);
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
