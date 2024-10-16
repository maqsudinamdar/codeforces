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



signed main() {
    fast;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t; cin >> t;
    while(t--) {
        int n, m, k; cin >> n >> m >> k;
        vector<vector<int > > grid(n + 1, vector<int> (m + 1));
        for (int x = 1; x <= n - k + 1; x++) {
            for (int y = 1; y <= m - k + 1; y++) {
                for (int i = x; i < x + k; i++) {
                    for (int j = y; j < y + k; j++) {
                        grid[i][j]++;
                    }
                }

            }
        }

        map<int, int> mp;
        for (int x = 1; x <= n; x++) {
            for (int y = 1; y <= m; y++) {
                mp[grid[x][y]]++;
            }
        }

        int w; cin >> w;
        vector<int> gorillas(w, 0);
        for (int i = 0; i < w; i++) cin >> gorillas[i];
        sort(gorillas.begin(), gorillas.end(), greater<int>());


        int ans = 0;
        int _i = 0;
        for (auto it = mp.rbegin(); it != mp.rend(); it++) {
            if (it->second > 0) {
                while (_i < w) {
                    if (it->second == 0) {
                        break;
                    }
                    ans += (it->first * gorillas[_i]);
                    it->second--;
                    _i++;
                }
            }
        }
        cout << ans;
        cout << "\n";
    }
    return 0;
}
