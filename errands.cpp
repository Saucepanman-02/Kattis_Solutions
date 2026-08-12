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
#define LSOne(x) (x&(x-1))^x


map<string, pdd> mp;
map<string, int> mc;
int n;

double dist(pdd a, pdd b) {
    return sqrt(abs(a.f-b.f)*abs(a.f-b.f)+abs(a.s-b.s)*abs(a.s-b.s));
}

int main() {
    speedup
    cin >> n;
    int c = 1;
    for (int i = 0; i < n; i++) {
        string st; cin >> st;
        double x, y; cin >> x >> y;
        mp[st] = {x, y};
        if (st == "home") {
            mc[st] = 0;
        }else if (st == "work") {
            mc[st] = n-1;
        }else {
            mc[st] = c++;
        }
    }
    string st; getline(cin, st);
    while (getline(cin, st)) {
        stringstream ss(st);
        string x;
        vector<string> a;
        a.push_back("home");
        while (ss >> x) {
            a.push_back(x);
        }
        int sz = a.size();
        vector<vector<db>> dp((1<<sz), vector<db>(sz, 1e9));
        vector<vi> p((1<<sz), vi(sz, -1));
        dp[1][0] = 0;
        for (int mask = 1; mask < (1<<sz); mask++) {
            for (int u = 1; u < sz; u++) {
                if (mask&(1<<u)) {
                    for (int v = 0; v < sz; v++) {
                        if ((mask&(1<<v)) && u != v) {
                            if (dp[mask][u]>dp[mask^(1<<u)][v]+dist(mp[a[u]], mp[a[v]])){
                                dp[mask][u] = dp[mask^(1<<u)][v]+dist(mp[a[u]], mp[a[v]]);
                                p[mask][u] = v;
                            }
                        }
                    }
                }
            }
        }
        double ans = 1e9; int cu = -1;
        for (int i = 1; i < sz; i++) {
            if (dp[(1<<sz)-1][i]+dist(mp[a[i]], mp["work"]) < ans) {
                ans = dp[(1<<sz)-1][i]+dist(mp[a[i]], mp["work"]);
                cu = i;
            }
        }
        vector<string> ar;
        int mask = (1<<sz)-1;
        while (mask != 1) {
            ar.push_back(a[cu]);
            int pr = p[mask][cu];
            mask ^= (1<<cu);
            cu = pr;
        }

        //reverse(ar.begin(), ar.end());
        for (string sr: ar) {
            cout << sr << ' ';
        }
        cout << endl;
    }
    return 0;
}
