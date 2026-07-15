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

bool cmp(pdi&a, pdi&b) {
    return a.f > b.f;
}

int main() {
    db t; int n; cin >> t >> n;
    priority_queue<pdi> pq;
    db mn = 1e9;
    for (int i = 0; i < n; i++) {
        int c; cin >> c;
        mn = min(mn, (db)c);
        pq.push({c, 1});
    }
    int cnt = 0;
    while (mn/pq.top().f < t) {
        pdi cur = pq.top(); pq.pop();
        db ful = cur.f*cur.s; cur.s++;
        cur.f = ful/cur.s;
        mn = min(mn, cur.f);
        pq.push(cur);
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}
