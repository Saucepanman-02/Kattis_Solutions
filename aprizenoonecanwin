#include <bits/stdc++.h>

using namespace std;

#define usopen(filename) do{freopen(filename".in", "r", stdin); freopen(filename".out", "w", stdout);}while(0);
#define f first
#define s second
#define ll long long
#define db double
#define pii pair<int, int>
#define pdd pair<db, db>

int main(){
    int n, x; cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    if (n == 1){
        cout << 1 << endl;
        return 0;
    }
    sort(a.begin(), a.end());
    int ans = 1;
    for (int i = 1; i < n; i++){
        if (a[i]+a[i-1] <= x){
            ans = i+1;
        }else{
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
