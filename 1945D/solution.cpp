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


void solve(int n, int m, vector<int>& a, vector<int>& b) {
    int pref = 0, b_sum = 0;
    for (int i = 0; i < n - m; i++) {
        if (a[i] < b[i]) {
            pref += a[i];
            pref += b_sum;
            b_sum = 0;
        } else {
            b_sum += b[i];
        }
    }
    int res = LLONG_MAX;
    for (int i = n - m; i < n; i++) {
        res = min(res, pref + b_sum + a[i]);
        b_sum += b[i];
    }
    cout << res;
}

signed main() {
    fast;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        reverse(a.begin(), a.end());
        
        for (int i = 0; i < n; i++) cin >> b[i];
        reverse(b.begin(), b.end());
        solve(n, m, a, b);
        cout << "\n";
    }
    return 0;
}
