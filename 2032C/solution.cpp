/**
 *    author:  maq5ud     
**/
#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define int                  long long



void solve(int n, vector<int>& a) {
    sort(a.begin(), a.end());
    int ans = LLONG_MAX;
    for (int i = 0; i + 1 < n; i++) {
        int left = i + 1, right = n - 1, index = i + 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (a[i] + a[i + 1] > a[mid]) {
                index = mid, left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        ans = min(ans, n - (index - i + 1));
    }
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
        vector<int> a(n); for (int i = 0; i < n; i++) cin >> a[i];
        solve(n, a);
        cout << "\n";
    }
    return 0;
}
