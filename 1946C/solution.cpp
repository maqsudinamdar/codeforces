/**
 *    author:  maq5ud     
**/
#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endl                '\n'
#define int                  long long
#define pb                  push_back
#define ppb                 pop_back
#define pf                  push_front
#define ppf                 pop_front
#define all(x)              (x).begin(),(x).end()
#define uniq(v)             (v).erase(unique(all(v)),(v).end())
#define sz(x)               (int)((x).size())
#define fr                  first
#define sc                  second
#define pii                 pair<int,int>
#define rep(i,a,b)          for(int i=a;i<b;i++)

int CNT = 0;

void dfs(int node, int par, int x, vector<int>& size, vector<vector<int > >& adj) {
    size[node] = 1;
    for (int child: adj[node]) {
        if (child != par) {
            dfs(child, node, x, size, adj);
            size[node] += size[child];
        }
    }
    if (size[node] >= x) {
        size[node] = 0;
        CNT++;
    }
}

int check(int mid, vector<int>& size, vector<vector<int > > & adj) {
    CNT = 0;
    dfs(1, 0, mid, size, adj);
    return CNT - 1;
}
 

signed main() {
    fast;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t; cin>>t;
    while(t--) {
        int n, k; cin >> n >> k;
        vector<vector<int > > adj(n + 1);
        for (int i = 0; i < n - 1; i++) {
            int u, v; cin >> u >> v;
            adj[u].pb(v); 
            adj[v].pb(u);
        }
        vector<int> size(n + 1);
        int l = 1, h = n, mid = 0;
        int ans = l;
        while (l <= h) {
            mid = l + (h - l) / 2;
            int temp = check(mid, size, adj);
            if (temp >= k) {
                ans = mid;
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}