#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <cmath>
#include <unordered_set>
#include <cstring>
#include <algorithm>
#include <numeric>
using namespace std;

#define speedup ios_base::sync_with_stdio(true); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long
#define INF 1e9
const int MAXN = 1200;

double memo[10][120];

int main() {
    speedup
    ll n, k;
    while (cin >> k >> n) {
        if (k == 0){
            cout << 100 << '\n';
            continue;
        }
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 120; j++) {
                memo[i][j] = 0;
            }
        }
        for (int i = 0; i <= k; i++) {
            memo[i][1] = 1;
        }
        for (int j = 2; j <= n; j++) {
            for (int i = 0; i <= k; i++) {
                if (i == 0) {
                    memo[i][j] = memo[i][j - 1] + memo[i + 1][j - 1];
                } else if (i == k) {
                    memo[i][j] = memo[i][j - 1] + memo[i - 1][j - 1];
                } else {
                    memo[i][j] = memo[i][j - 1] + memo[i + 1][j - 1] + memo[i - 1][j - 1];
                }
            }
        }
        double ans = 0;
        for (int i = 0; i <= k; i++) {
            ans += memo[i][n];
        }
       double denom = pow((double)(k+1), n), multiply = 100;
        printf("%0.7f \n", (ans/denom) * multiply);
    }
    return 0;
}
