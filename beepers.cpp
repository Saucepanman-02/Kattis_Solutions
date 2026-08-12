#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
using namespace std;

#define ll long long

int dist(pair<int, int> p1, pair<int, int> p2){
    return abs(p1.first-p2.first)+abs(p1.second-p2.second);
}

int main(){
    int t; cin >> t;
    while (t--) {
        int sx, sy;
        cin >> sx >> sy;
        int x, y;
        cin >> x >> y;
        int n;
        cin >> n;
        vector<pair<int, int>> points(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> points[i].first >> points[i].second;
        }
        points[0] = {x, y};
        n++;
        vector<vector<int>> dp((1 << n), vector<int>(n, 1e9));
        for (int i = 0; i < n; i++) {
            dp[(1 << i)][i] = 0;
        }
        for (int mask = 1; mask < (1 << n); mask++) {
            for (int i = 1; i < n; i++) {
                if (mask & (1 << i)) {
                    for (int j = 0; j < n; j++) {
                        if (mask & (1 << i) && (i != j)) {
                            dp[mask][i] = min(dp[mask][i], dp[mask ^ (1 << i)][j] + dist(points[i], points[j]));
                        }
                    }
                }
            }
        }
        int ans = 1e9;
        for (int i = 0; i < n; i++) {
            if (dp[(1 << n) - 1][i] + dist(points[i], points[0]) < ans) {
                ans = dp[(1 << n) - 1][i] + dist(points[i], points[0]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}b
