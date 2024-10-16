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

int nth_term_of_ap(int n, int a, int d) {
    return a + (n - 1) * d;
}


int f(int mul, int m, int n, int k) {
    int lo = 1, hi = 1e9, mid, val_idx = 1;
    while (hi >= lo) {
        mid = (lo + hi) / 2;
        int mid_th_term = nth_term_of_ap(mid, 1, 2) * mul;
        if (mid_th_term <= n) {
            val_idx = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    if (val_idx >= m) {
        return nth_term_of_ap(m, 1, 2) * mul;
    } else {
        mul = mul << 1;
        return f(mul, m - val_idx, n, k);
    }
}


signed main() {
    fast;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        int ans;
        if (k <= (n + 1) / 2) {
            ans = nth_term_of_ap(k, 1, 2);
        } else {
            int m = k - ((n + 1) / 2);
            int mul = 1 << 1;
            ans = f(mul, m, n, k);
        }
        cout << ans;
        cout << "\n";
    }
    return 0;
}
