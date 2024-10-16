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


int k_is_equal_to_1(int k, vector<int>& a) {
    int ans = a[0];
    int n = a.size();
    for (int i = 0; i < n - 1; i++) {
        ans = min(ans, a[i + 1] - a[i]);
    }
    return ans;
}


int k_is_equal_to_2(int k, vector<int>& a) {
    int n = a.size();
    int ans = a[0];
   
    for (int i = 0; i < n - 1; i++) {
        ans = min(ans, a[i + 1] - a[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            int tmp = a[i] - a[j];
            int p = lower_bound(a.begin(), a.end(), tmp) - a.begin();
            if (p < n) {
                ans = min(ans, a[p] - tmp);
            } 
            if (p > 0) {
                ans = min(ans, tmp - a[p - 1]);
            }
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
        int tmp;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int ans = 0;
        if (k > 2) {
            ans = 0;
        } else {
            sort(a.begin(), a.end());
            if (k == 1) {
                ans = k_is_equal_to_1(k, a);
            } else if (k == 2) {
                ans = k_is_equal_to_2(k, a);
            }
            
        }
        cout << ans;
        cout << "\n";
    }
    return 0;
}
