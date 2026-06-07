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
    if (a.s == b.s){
        return a.f > b.f;
    }
    return a.s > b.s;
}

int main(){
    int n, p; cin >> n >> p;
    vector<ll> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    if (a[p] > 300){
        cout << 0 << ' ' << 0 << endl;
        return 0;
    }
    ll cur = a[p];
    int ans = 1;
    ll pl = cur;
    a[p] = INT_MAX;
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++){
        if (cur+a[i] <= 300){
            cur += a[i];
            pl += cur;
            ans++;
        }else{
            break;
        }
    }
    cout << ans << ' ' << pl << endl;
    return 0;
}
