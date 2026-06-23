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

unordered_map<string, vector<string>> m;
unordered_map<string, int> sv;
unordered_map<int, string> vs;

vector<vector<int>> g;
vector<int> vis;
vector<int> ans;

void dfs(int c){
    if (vis[c]){
        return;
    }
    vis[c] = true;
    for (int v: g[c]){
        dfs(v);
    }
    ans.push_back(c);
}
int main() {
    speedup
    int n; cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for (int i = 0; i < n; i++){
        string line;
        getline(cin, line);

        stringstream ss(line);
        vector<string> words;
        string word;

        while (ss >> word) {
            words.push_back(word);
        }
        if (words.empty()){
            continue;
        }
        word = words[0];
        //cout << i << ' ' << word << endl;
        word.pop_back();
        reverse(words.begin(), words.end());
        words.pop_back();
        m[word] = words;
        sv[word] = i;
        vs[i] = word;
    }
    g.resize(n);
    vis.assign(n, false);
    for (int i = 0; i < n; i++){
        for (string st: m[vs[i]]){
            g[sv[st]].push_back(i);
        }
    }
    string sr; cin >> sr;
    int v = sv[sr];
    dfs(v);
    reverse(ans.begin(), ans.end());
    for (int c: ans){
        cout << vs[c] << '\n';
    }
    return 0;
}
