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

int a, d;
db th;
vector<pdd> ascent, descent;

int solve(db t){
    db as = 0, ds = 0;
    db ct = 0;
    for (int i = 0; i < a; i++){
        if (ct + ascent[i].s <= t){
            as += ascent[i].f;
            ct += ascent[i].s;
        }else{
            as += ascent[i].f* (t-ct)/ascent[i].s;
            break;
        }
    }
    ct = 0;
    for (int i = 0; i < d; i++){
        if (ct + descent[i].s <= t){
            ds += descent[i].f;
            ct += descent[i].s;
        }else{
            ds += descent[i].f * (t-ct)/descent[i].s;
            break;
        }
    }
    if (as+ds < th){
        return -1;
    }else{
        return 1;
    }
}

int main(){
    speedup
    cin >> a >> d;
    th = 0;
    ascent.resize(a);
    descent.resize(d);
    for (int i = 0; i < a; i++){
        cin >> ascent[i].f >> ascent[i].s;
        th += ascent[i].f;
    }
    for (int i = 0; i < d; i++){
        cin >> descent[i].f >> descent[i].s;
    }
    db l = 0, h = 1e6;
    while (h-l > EPS){
        db m = (h+l)/2;
        if (solve(m) == 1){
            h = m;
        }else{
            l = m;
        }
    }
    printf("%.7f\n", (l+h)/2);
    return 0;
}
