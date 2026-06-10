#include <bits/stdc++.h>

using namespace std;

#define speedup ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define usopen(filename) do{freopen(filename".in", "r", stdin); freopen(filename".out", "w", stdout);}while(0);
#define f first
#define s second
#define ll long long
#define db double
#define pii pair<int, int>
#define pdd pair<db, db>
#define vi vector<int>

int n; 
vi a, b;

bool solve(int w){
    vi va, vb;
    for (int i = 0; i < n; i++){
        if (a[i] > w){
            va.push_back(a[i]);
        }
        if (b[i] > w){
            vb.push_back(b[i]);
        }
    }
    int sz = va.size();
    if (sz%2 == 1){
        return false;
    }
    bool flag = true;
    for (int i = 0; i < sz; i += 2){
        flag &= (va[i] == va[i+1]);
    }
    sz = vb.size();
    if (sz%2 == 1){
        return false;
    }
    for (int i = 0; i < sz; i += 2){
        flag &= (vb[i] == vb[i+1]);
    }
    return flag;
}

int main(){
    speedup
    cin >> n;
    a.resize(n), b.resize(n);
    int ans = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        ans = max(ans, a[i]);
    }
    for (int i = 0; i < n; i++){
        cin >> b[i];
        ans = max(ans, b[i]);
    }
    int l = 0, r = 1e9;
    while (r >= l){
        int m = (r+l)/2;
        if (solve(m)){
            ans = m;
            r = m-1;
        }else{
            l = m+1;
        }
    }
    cout << ans << endl;
    return 0;
}
