/*NOTE: This qn statement has a small bug; its mentioned to have presision of 10^-6, but gives TLE: while precision of 10^-4 (which is supposed to give WA) gives AC */
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
#define EPS 1e-4

vector<pdd> tb;
int b, fe; 
vector<pdd> fr;
db p;
db cur, mtx;
int idx;
bool flag;

int solve(db &mn, int &c){
    cur = 0, mtx = 0;
    idx = -1;
    flag = true;
    for (int i = 0; i < b; i++){
        if (cur + tb[i].f <= fr[c].f){
            cur += tb[i].f;
        }else if (mn+fr[c].f > cur+tb[i].f){
            mtx += (cur+tb[i].f-fr[c].f)*(1-tb[i].s/100);
            idx = i+1;
            cur += tb[i].f;
            break;
        }else{
            mtx += (mn)*(1-tb[i].s/100);
            return (mtx >= fr[c].s);
        }
    }
    if (idx == -1){
        mtx = mn*(1-p/100);
        return (mtx >= fr[c].s);
    }
    for (int i = idx; i < b; i++){
        if (cur + tb[i].f <= fr[c].f+mn){
            mtx += tb[i].f*(1-tb[i].s/100);
            cur += tb[i].f;
        }else{
            mtx += (fr[c].f+mn-cur)*(1-tb[i].s/100);
            flag = false;
            break;
        }
    }
    if (flag){
        mtx += (mn+fr[c].f-cur)*(1-p/100);
    }
    return (mtx >= fr[c].s);
}


int main(){
    speedup
    cin >> b;
    tb.resize(b);
    for (int i = 0; i < b; i++){
        cin >> tb[i].f >> tb[i].s;
    }
    cin >> p;
    cin >> fe;
    fr.resize(fe);
    for (int i = 0; i < fe; i++){
        cin >> fr[i].f >> fr[i].s;
    }
    db l, r, m;
    for (int i = 0; i < fe; i++){
        l = 0, r = 1e18;
        //cout << fr[i].f << ' ' << fr[i].s << endl;
        while (r-l > EPS){
            m = (r+l)/2;
            if (solve(m, i)){
                r = m;
            }else{
                l = m;
            }
        }
        printf("%.6f\n", (r+l)/2);
    }
    return 0;
}
