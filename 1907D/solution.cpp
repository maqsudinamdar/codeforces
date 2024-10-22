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

int upperBound(int d, vector<int>& a) {
    int lo = 0, hi = a.size() - 1, mid;
    while (lo <= hi) {
        mid = (lo + hi) / 2;
        if (a[mid] <= d) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return hi;
}

signed main() {
    fast;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t; cin >> t;
    while(t--) {
        int n, k, q; 
        cin >> n >> k >> q;
        vector<int> a(k + 1, 0), b(k + 1, 0);
        for (int i = 1; i <= k; i++) cin >> a[i];
        for (int i = 1; i <= k; i++) cin >> b[i];
        while (q--) {
            int d; cin >> d;
            int i = upperBound(d, a);
            if (a[i] == d) {
                cout << b[i] << " ";
                continue;
            }
            int ans = b[i] + (d-a[i])*(b[i+1]-b[i])/(a[i+1]-a[i]);
            cout << ans << " ";
        }
        cout << "\n";
    }
    return 0;
}
