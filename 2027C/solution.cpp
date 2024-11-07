/**
 *    author:  maq5ud     
**/
#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define int                  long long

int dfs(int src, map<int, vector<int > >& adj, map<int, bool>& vis) {
    vis[src] = true;
    int ans = src;
    for (int neighbor: adj[src]) {
        if (!vis[neighbor]) {
            int tmp = dfs(neighbor, adj, vis);
            ans = max(ans, tmp);
        }
            
    }
    return ans;
}

void solve(int n, vector<int>& a) {
    map<int, vector<int > > adj;
    for (int i = 1; i <= n; i++) {
        int u = a[i] + i - 1;
        int v = u + i - 1;
        adj[u].push_back(v);
    }
    map<int, bool> vis;
    int ans = dfs(n, adj, vis);
    ans = max(ans, n);
    cout << ans;
}


signed main() {
    fast;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> a(n + 1); for (int i = 1; i <= n; i++) cin >> a[i];
        solve(n, a);
        cout << "\n";
    }
    return 0;
}
