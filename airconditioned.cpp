#include <bits/stdc++.h>

using namespace std;

#define usopen(filename) do{freopen(filename".in", "r", stdin); freopen(filename".out", "w", stdout);}while(0);
#define f first
#define s second
#define ll long long
#define db double
#define pii pair<int, int>
#define pdd pair<db, db>

bool cmp(pii &a, pii &b){
    if (a.f == b.f){
        return a.s > b.s;
    }
    return a.f < b.f;
}

int main(){
    int n; cin >> n;
    vector<pii> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i].f >> a[i].s;
    }
    sort(a.begin(), a.end(), cmp);
    int ans = 0;
    int cur = a[0].s;
    int c = 0;
    while (c < n){
        cur = a[c].s; c++;
        while (c < n && a[c].f <= cur){
            cur = min(cur, a[c].s); c++;
        }
        ans++;
    }
    cout << ans << endl;
    return 0;
}
