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


int solve(int n, vector<int>& a) {
    for (int i = 2; i <= n / 2; i++) {
        if (a[i] == a[i - 1] or a[n - i + 1] == a[n - i + 2]) {
            swap(a[i], a[n - i + 1]);
            // cout << i << " ";
        }
    }

    int ans = 0;
    for (int i = 2; i <= n; i++) {
        ans += (a[i] == a[i - 1]);
    }
    return ans;
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
        int ans = solve(n, a);
        // cout << "ans: ";
        cout << ans;
        cout << "\n";
    }
    return 0;
}
