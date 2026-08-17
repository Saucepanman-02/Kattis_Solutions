#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <unordered_set>
#include <cstring>
#include <algorithm>
using namespace std;

#define speedup ios_base::sync_with_stdio(true); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long
#define INF 1e9
const int MAXN = 1200;

string dp[45][MAXN];

int main() {
    speedup
    for (int i = 0; i < 45; i++){
        for (int j = 0; j < MAXN; j++){
            dp[i][j] = "-1";
        }
    }
    int l, w; cin >> l >> w;
    dp[0][0] = "";
    for (int i = 1; i <= 26; i++){
        dp[1][i] = char(i-1+'a');
    }
    for (int i = 2; i <= l; i++){
        for (int j = 1; j <= w; j++){
            for (int k = 1; k <= min(26, j); k++){
                if (dp[i-1][j-k] != "-1"){
                    dp[i][j] = dp[i-1][j-k]+char(k-1+'a');
                }
            }
        }
    }
    if (dp[l][w] != "-1"){
        cout << dp[l][w] << endl;
    }else{
        cout << "impossible" << endl;
    }
    return 0;
}
