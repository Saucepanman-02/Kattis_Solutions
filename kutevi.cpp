#include <bits/stdc++.h>
using namespace std;

#define speedup ios_base::sync_with_stdio(false); cin.tie(nullptr);

int main() {
    speedup

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int &x : a)
        cin >> x, x %= 360;

    vector<bool> vis(360, false);
    queue<int> q;

    vis[0] = true;
    q.push(0);

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        for (int y : a) {
            int p = (x + y) % 360;
            int m = (x - y + 360) % 360;

            if (!vis[p]) {
                vis[p] = true;
                q.push(p);
            }

            if (!vis[m]) {
                vis[m] = true;
                q.push(m);
            }
        }
    }

    while (k--) {
        int x;
        cin >> x;
        cout << (vis[x % 360] ? "YES\n" : "NO\n");
    }
}
