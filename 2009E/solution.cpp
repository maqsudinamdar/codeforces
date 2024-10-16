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


int _sum_of_ap(int n, int k) {
    return ( (n * (n + 1)) / 2 - (k * (k - 1)) / 2);
}



int binary_search(int n, int k) {
    int total = _sum_of_ap(n + k - 1, k);
    int l = k, r = n + k - 1, mid;
    int ans = INT_MAX;
    while (l <= r) {
        mid = (l + r) / 2;
        int prefix_sum = _sum_of_ap(mid, k);
        int suffix_sum = total - prefix_sum;

        int diff = abs(prefix_sum - suffix_sum);
        ans = min(ans, diff);
        if (prefix_sum < suffix_sum) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
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
        int n, k; cin >> n >> k;
        int ans = binary_search(n, k);
        cout << ans;
        cout << "\n";
    }
    return 0;
}
