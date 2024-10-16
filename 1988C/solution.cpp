/**
 *    author:  maq5ud     
**/
#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endl                '\n'
#define int                 unsigned long long
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


void f(int idx, int num, int n, vector<int>& ans) {
    if (idx >= 64) return;
    if ((num >> idx) & 1) {
        
        int tmp = num;
        for (int i = 0; i < idx; i++) {
            if ((n >> i) & 1) {
                if (!((num >> i) & 1)) {
                    // int x = (1 << i);
                    tmp = tmp | (1LL << i);
                }
            }
        }
        // int y = (1 << idx); // 2.1 create a number whose ith bit is set
        tmp = tmp & (~(1LL << idx)); // 2.2 unset the ith bit of num
        if (tmp && tmp < num && (tmp | num) == n) {   // 3. check if bitwise OR of tmp and num is n
            ans.push_back(tmp);
            f(idx + 1, tmp, n, ans);
        } else {
            f(idx + 1, num, n, ans);
        }
    } else {
        f(idx + 1, num, n, ans);
    }
}


signed main() {
    fast;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t; cin >> t;
    while(t--) {
        int n; 
        cin >> n;
        vector<int> ans;
        int num = n;
        ans.push_back(num);
        f(0, n, n, ans);
        int k = ans.size();
        cout << k << "\n";
        for (auto it = ans.rbegin(); it != ans.rend(); it++) {
            cout << *it << " ";
        }
        cout << "\n";
    }
    return 0;
}
