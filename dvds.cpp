#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define speedup ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

int main() {
    speedup
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> v1(n);
        vector<int> v2(n);
        for (int i = 0; i < n; i++) {
            cin >> v1[i];
            v2[i] = i + 1;
        }
        int idx = 0;
        for (int i = 0; i < n; i++) {
            if (v1[i] == v2[idx]) {
                idx++;
            }
        }
        cout << n - idx << endl;
    }
    return 0;
}
