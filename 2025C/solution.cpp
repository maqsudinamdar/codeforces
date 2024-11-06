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


void solve(int n, int k, vector<int>& a) {
    map<int, int> mp; for (int i = 0; i < n; i++) mp[a[i]]++;
    int ans = LLONG_MIN;
    int size = 0;
    int start_val = -1, end_val = -1;
    int window_count = 0;
    for (auto it = mp.begin(); it != mp.end(); it++) {
        int val = it->first, count = it->second;
        if (start_val == -1) {
            start_val = val, window_count += count;
            end_val = val;
            size++;
        } else if (val == end_val + 1) {
            if (size < k) {
                end_val = val;
                window_count += count;
                size++;
            } else {
                auto start_it = mp.find(start_val);
                auto nxt_it = start_it;
                nxt_it++;
                if (nxt_it->first == start_it->first + 1) {
                    window_count -= mp[start_val];
                    window_count += count;
                    start_val = nxt_it->first;
                    end_val = val;
                } else {
                    start_val = val;
                    end_val = val;
                    window_count = count;
                    size = 1;
                }
            }
        } else {
            start_val = val;
            end_val = val;
            window_count = count;
            size = 1;
        }
        ans = max(ans, window_count);
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
        int n, k; cin >> n >> k;
        int min_val = INT_MAX, max_val = INT_MIN;
        vector<int> a(n); for (int i = 0; i < n; i++) cin >> a[i];
        solve(n, k, a);
        cout << "\n";
    }
    return 0;
}
