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

bool helper(int x, int d, vector<int>& a, vector<int>& c) {
    int power = 0;
    for (int i = 0; i < a.size(); i++) {
        power += (a[i] * (x / c[i]));
        if (power >= d) return true;
    }
    return false;
}


signed main() {
    fast;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t; cin >> t;
    while(t--) {
        int h, n; cin >> h >> n;
        vector<int> a(n), c(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> c[i];
        
        int total_attack = 0; for (int i = 0; i < n; i++) total_attack += a[i];
        if (total_attack >= h) {
            cout << 1 << "\n";
            continue;
        } else {
            int remainingAttack = h - total_attack;
            int lo = 0, hi = 1e11, mid;
            while (lo < hi) {
                mid = (hi + lo) / 2;
                if (helper(mid, remainingAttack, a, c)) {
                    hi = mid;
                } else {
                    lo = mid + 1;
                }
            }
            int ans = (hi + 1);
            cout << ans << "\n";
        }
    }
    return 0;
}
