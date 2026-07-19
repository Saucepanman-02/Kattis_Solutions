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
    int ln, ar; 
    while(cin >> ln >> ar){
        vector<int> r, l;
        vector<int> a;
        int lans = -1, rans = -1;
        for (int i = 0; i < ar; i++){
            int x; char c; cin >> x >> c;
            if (c=='R'){
                r.push_back(x);
            }else{
                l.push_back(x);
            }
            a.push_back(x);
        }
        sort(a.begin(), a.end());
        sort(r.begin(), r.end());
        sort(l.begin(), l.end());
        if (!r.empty()){
            rans = ln-r[0];
        }
        if (!l.empty()){
            lans = l.back();
        }
        cout << "The last ant will fall down in " << max(lans, rans) << " seconds - started at ";
        if (lans > rans){
            cout << a[l.size()-1];
        }else if (rans > lans){
            cout << a[a.size()-r.size()];
        }else{
            int x = a[l.size()-1], y = a[a.size()-r.size()];
            cout << min(x, y) << " and " << max(x, y);
        }
        cout << "." << '\n';
    }

    return 0;
}
