#include <iostream>
using namespace std;

#define speedup ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

int main() {
    speedup
    int t;
    cin >> t;
    while (t--) {
        int l, n;
        cin >> l >> n;
        int mn = 0, mx = 0;
        for (int i = 0; i < n; i++){
            int x;
            cin >> x;
            x = (x < l-x)? x: l-x;
            if (x > mn){
                mn = x;
            }
            if (l-x > mx){
                mx = l-x;
            }
        }
        cout << mn << ' ' << mx << endl;
    }
    return 0;
}
