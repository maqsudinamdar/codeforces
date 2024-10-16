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
        int n, q; 
        cin >> n >> q;

        vector<string> colors(n + 1);
        for (int i = 1; i <= n; i++) {
            string s; cin >> s;
            colors[i] = s;
        }

        map<string, vector<int> > mp;
        for (int i = 1; i <= n; i++) {
            // string s; cin >> s;
            mp[colors[i]].push_back(i);
        }

        while (q--) {
            int src, dest; cin >> src >> dest;
            if (dest < src) {
                swap(src, dest);
            }
            int ans = INT_MAX;
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    string tmp = "";
                    tmp += colors[src][i];
                    tmp += colors[dest][j];
                    sort(tmp.begin(), tmp.end());
                    if (mp.find(tmp) != mp.end()) {
                        auto it = lower_bound(mp[tmp].begin(), mp[tmp].end(), src);
                        if (it != mp[tmp].end()) {
                            int tmp_ans = abs(*it - dest) + abs(*it - src);
                            ans = min(ans, tmp_ans);
                        }
                        if (it != mp[tmp].begin()) {
                            it--;
                            int tmp_ans = abs(*it - dest) + abs(*it - src);
                            ans = min(ans, tmp_ans);
                        }
                    }
                }
            }
            if (ans == INT_MAX) {
                ans = -1;
            }
            cout << ans << "\n";
        }
    }
    return 0;
}
