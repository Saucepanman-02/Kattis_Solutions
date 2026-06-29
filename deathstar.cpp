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

int main(){
    int n; cin >> n;

    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    vi ans(n);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            ans[i] |= a[i][j];
        }
    }
    for (int i = 0; i < n; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}
