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

bool can_sell_all_cars(int n_customer, int x, vector<int>& cars) {
    int sum = 0;
    for (int car: cars) {
        sum += min(car, n_customer);
    }
    return sum <= n_customer * x;
}


int solve(int n, int x, vector<int>& cars) {
    int total_sum = 0;
    int max_a = INT_MIN;
    for (int car: cars) {
        total_sum += car;
        max_a = max(max_a, car);
    }
    int lo = max_a, hi = total_sum, mid, ans;
    while(lo <= hi) {
        mid = (lo + hi) /  2;
        if (can_sell_all_cars(mid, x, cars)) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
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
        int n, x; cin >> n >> x;
        vector<int> a(n); for (int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        int ans = solve(n, x, a);
        cout << ans;
        cout << "\n";
    }
    return 0;
}
