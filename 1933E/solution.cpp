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


double sum_of_ap(double n, double a, double d) {
    return (n / 2) * (2 * a + (n - 1) * d);
}
double func(double mid, double l, double u, vector<double>& prefix_sum) {
    double sections = prefix_sum[mid] - prefix_sum[l - 1];
    double d = -1;
    double a = u;
    double val = sum_of_ap(sections, a, d);
    return val;
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
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) cin >> a[i];
        vector<double> prefix_sum(n + 1);
        for (int i = 1; i <= n; i++) prefix_sum[i] += prefix_sum[i - 1] + a[i];
        int q; cin >> q;
        while (q--) {
            double l, u; cin >> l >> u;
            int lo = l, hi = n, mid_1 = 0, mid_2 = 0;
            while (hi - lo > 3) {
                mid_1 = lo + (hi - lo) / 3;
                mid_2 = hi - (hi - lo) / 3;
                double f1 = func(mid_1, l, u, prefix_sum);
                double f2 = func(mid_2, l, u, prefix_sum);
                if (f1 < f2) {
                    lo = mid_1 + 1; 
                } else if (f1 > f2) {
                    hi = mid_2 - 1;
                } else {
                    lo = mid_1 + 1;
                    hi = mid_2 - 1;
                }
            }

            double max_val = INT_MIN, max_idx;
            for (int i = lo; i <= hi; i++) {
                double val = func(i, l, u, prefix_sum);
                if (val > max_val) {
                    max_val = val;
                    max_idx = i;
                }
            }
            cout << max_idx << " ";
        }
        cout << "\n";
    }
    return 0;
}
