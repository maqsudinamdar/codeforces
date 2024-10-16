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


int binarySearch(int x, int y) {
    int l = 0, r = abs(x - y);
    int ans = 0;
    while (l < r) {
        int mid = (l + r) / 2;
        int a = x + mid, b = y - mid;
        if (a <= b) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return x + ans;
}


int dfs(int parent, vector<vector<int > >& adj, vector<int>& val) {
    int ans = INT_MAX;
    int res_sum = INT_MAX;
    for (int child: adj[parent]) {
        int tmp = dfs(child, adj, val);
        if (parent == 1) {
            res_sum = min(tmp, res_sum);
            continue;
        }
        if (tmp > val[parent]) {
            int _tmp = binarySearch(val[parent], tmp);
            // cout << "c: " << child << " _t: " << _tmp << " t: " << tmp << endl;
            ans = min(ans, _tmp);
        } else {
            ans = min(ans, tmp);
        }
    }
    if (parent == 1) {
        return val[parent] + res_sum;
    }
    return ans == INT_MAX ? val[parent] : ans;
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
        vector<int> val(n + 1, 0);
        for (int i = 1; i <= n; i++) cin >> val[i];
        vector<vector<int > > adj(n + 1);
        for (int i = 2; i <= n; i++) {
            int tmp; cin >> tmp;
            adj[tmp].push_back(i);
        }
        int ans = dfs(1, adj, val);
        cout << ans;
        cout << "\n";
        // cout << "\n";
    }
    return 0;
}
