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
    int t; cin>>t;
    while(t--) {
        int n; cin >> n;
        map<int, int> mp;
        int tmp;
        for (int i = 1; i <= n; i++) {
            cin >> tmp;
            mp[tmp + i]++;
        }
        vector<int> ans;
        while(!mp.empty()) {
            auto lastEle = *mp.rbegin();
            ans.push_back(lastEle.first);
            mp.erase(lastEle.first);
            lastEle.second--;
            if (lastEle.second) {
                mp[lastEle.first - 1] +=  lastEle.second;
            }
        }
        for (int i = 0; i < n; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}