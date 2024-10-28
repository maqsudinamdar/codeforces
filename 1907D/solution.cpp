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

bool helper(int x, vector<vector<int > >& a) {
    int n = a.size();
    int curr_l = 0, curr_r = 0;
    for (int i = 0; i < n; i++) {
        int nxt_l = a[i][0], nxt_r = a[i][1];

        curr_l = max(curr_l - x, nxt_l);
        curr_r = min(curr_r + x, nxt_r);

        if (curr_l > curr_r) return false;
    }
    return true;
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
        vector<vector<int > > a(n, vector<int>(2)); 
        int l, r;
        for (int i = 0; i < n; i++) {
            cin >> l >> r;
            a[i][0] = l; a[i][1] = r;
        }
        int lo = 0, hi = 1e9, mid, ans;
        while (lo <= hi) {
            mid = (lo + hi) / 2;
            if (helper(mid, a)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        cout << ans;
        cout << "\n";
    }
    return 0;
}
