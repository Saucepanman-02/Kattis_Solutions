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
    int t; cin >> t;

    for (int c = 0; c < t; c++){
        int n, k; cin >> n >> k;
        cout << "Case #" << c+1 << ": " <<( (k%((1<<n)) == (1<<n)-1 ) ? "ON" : "OFF") << endl;
    }
}
