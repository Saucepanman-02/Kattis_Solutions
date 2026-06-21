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

vector<vector<int>> graph(10001);
vector<int> weight(10001);
bool vis[10001];
int sum = 0;

void dfs(int u){
    if (!vis[u]){
        vis[u] = true;
        sum += weight[u];
        for (int v: graph[u]){
            dfs(v);
        }
    }else{
        return;
    }

}
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> weight[i];
    }
    for (int i = 0; i < m; i++){
        int c1, c2;
        cin >> c1 >> c2;
        graph[c1].push_back(c2);
        graph[c2].push_back(c1);
    }
    bool flag = true;
    for (int i = 0; i < n; i++){
        if (!vis[i]){
            dfs(i);
            if (sum != 0){
                flag = false;
                break;
            }
        }
    }
    if (flag){
        cout << "POSSIBLE" << endl;
    }else{
        cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}
