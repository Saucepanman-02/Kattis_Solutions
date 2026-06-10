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

db x, y; 
vector<pair<pii, db>> a;
int n;

int solve(db vx){
    db cx = 0, cy = 0;
    for (int i = 0; i < n; i++){
        if (cy < a[i].f.f){
            cx += (a[i].f.f-cy)*vx;
        }
        cy = a[i].f.s;
        cx += (a[i].f.s-a[i].f.f)*vx*a[i].s;
    }
    cx += (y-cy)*vx;
    if (cx > x){
        return -1;
    }else{
        return 1;
    }
}

#define EPS 1e-9

int main(){
    cin >> x >> y;
    int sgn = (x > 0? 1: -1);
    x = abs(x);
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++){
        cin >> a[i].f.f >> a[i].f.s >> a[i].s;
    }
    if (x == 0){
        cout << 0 << endl;
        return 0;
    }
    sort(a.begin(), a.end());
    db l = 0, r = 1e9;
    while (r-l > EPS){
        db m = (r+l)/2;
        int cr = solve(m);
        if (cr < 0){
            r = m;
        }else{
            l = m;
        }
    }
    printf("%.8f\n", sgn*(r+l)/2);
    return 0;
}
