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
#define vll vector<ll>

vector<string> g;
vector<vector<bool>> con, vis;
int cnt, n;
vi ca(6);
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

void ff(int x, int y, int c){
    if (x < 0 || x >= n){
        return;
    }
    if (y < 0 || y >= n){
        return;
    }
    if (vis[x][y]){
        return;
    }
    vis[x][y] = true;
    if (con[x][y] || g[x][y] == c+'1'){
        for (int i = 0; i < 4; i++){
            ff(x+dx[i], y+dy[i], c);
        }
    }
    if (!con[x][y] && g[x][y] == c+'1'){
        ca[c]++;
    }
}

void cff(int x, int y, int c){
    if (x < 0 || x >= n){
        return;
    }
    if (y < 0 || y >= n){
        return;
    }
    if (vis[x][y]){
        return;
    }
    vis[x][y] = true;
    if (con[x][y]){
        for (int i = 0; i < 4; i++){
            int cx = x+dx[i], cy = y+dy[i];
            if (cx < 0 || cx >= n || cy < 0 || cy >= n){
                continue;
            }
            if (g[cx][cy] == c+'1' || con[cx][cy]){
                cff(cx, cy, c);
            }
        }
    }else if (g[x][y] == c+'1'){
        con[x][y] = true; cnt++;
        for (int i = 0; i < 4; i++){
            cff(x+dx[i], y+dy[i], c);
        }
    }
}

int main() {
    int t; cin >> t;
    while (t--){
        cin >> n;
        cnt = 1;
        g.resize(n);
        con.assign(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++){
            cin >> g[i];
        }
        vi ac = {0, 0, 0, 0, 0, 0};
        con[0][0] = true;
        int ans = 0;
        int ci = g[0][0]-'1';
        vis.assign(n, vector<bool>(n, false));
        cff(0, 0, ci);
        while (cnt < n*n){
            ca.assign(6, 0);
            for (int i = 0; i < 6; i++){
                vis.assign(n, vector<bool>(n, false));
                ff(0, 0, i);
            }
            int mx = ca[0], mc = 0;
            for (int i = 1; i < 6; i++){
                if (ca[i] > mx){
                    mx = ca[i];
                    mc = i;
                }
            }
            vis.assign(n, vector<bool>(n, false));
            cff(0, 0, mc);
            ac[mc]++;
            ans++;
        }
        cout << ans << '\n';
        for (int i = 0; i < 6; i++){
            cout << ac[i];
            if (i != 5) {
                cout << ' ';
            }
        }
        if (t)
            cout << '\n';
    }
    return 0;
}
