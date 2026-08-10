
#include <iostream>
#include <vector>
#include <climits>
#include <set>
#include <cstring>
#include <algorithm>
using namespace std;

#define speedup ios_base::sync_with_stdio(true); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long
const int MAXN = 1e5+10;

int hot_dogs[MAXN];
int buns[MAXN];

int main() {
    speedup
    for (int i = 0; i < MAXN; i++){
        hot_dogs[i] = 1e8; buns[i] = 1e8;
    }
    int h; cin >> h;
    int max_hot_dog = 0;
    hot_dogs[0] = 0, buns[0] = 0;
    for (int i = 0; i < h; i++){
        int hi; cin >> hi;
        for (int j = MAXN-max_hot_dog-1; j >= 0; j--){
            if (hot_dogs[hi+j] > 1+hot_dogs[j]){
                hot_dogs[hi+j] = 1+hot_dogs[j];
            }
        }
    }
    int w; cin >> w;
    int max_buns = 0;
    for (int i = 0; i < w; i++){
        int bi; cin >> bi;
        for (int j = MAXN - max_buns - 1; j >= 0; j--){
            if (buns[bi+j] > 1+buns[j]){
                buns[bi+j] = 1+buns[j];
            }
        }
    }
    int ans = 1e8;
    for (int i = 1; i < MAXN; i++){
        ans = min(ans, hot_dogs[i]+buns[i]);
    }
    if (ans >= 1e8){
        cout << "impossible" << endl;
    }else{
        cout << ans << endl;
    }
    return 0;
}
