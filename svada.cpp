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
#define EPS 1e-9

int t0, n, m;
vector<pii> a, b;

int solve(int t){
    int ca = 0, cb = 0;
    for (int i = 0; i < n; i++){
        if (t >= a[i].f){
            ca += (t-a[i].f)/a[i].s+1;
        }
    }

    for (int i = 0; i < m; i++){
        if (t0-t >= b[i].f){
            cb += (t0-t-b[i].f)/b[i].s+1;
        }
    }
    if (ca > cb){
        return 1;
    }else if (ca < cb){
        return -1;
    }else{
        return 0;
    }
}


int main(){
    speedup
    cin >> t0;
    cin >> n; a.resize(n);
    for (int i = 0; i  < n; i++){
        cin >> a[i].f >> a[i].s;
    }
    cin >> m; b.resize(m);
    for (int i = 0; i < m; i++){
        cin >> b[i].f >> b[i].s;
    }
    int l = 0, r = t0;
    while (r >= l){
        int md = (r+l)/2;
        int cr = solve(md);
        if (cr == 1){
            r = md-1;
        }else if (cr == -1){
            l = md+1;
        }else{
            cout << md << endl;
            return 0;
        }
    }
    cout << (r+l)/2 << endl;
    return 0;
}
