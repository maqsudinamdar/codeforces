/**
 *    author:  maq5ud     
**/
#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endl                '\n'
#define int                 long long
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
 
const int mod = 1e9+7;
const int N = 1e9+10;
 
 
 bool canKillAllMonster(int x, int k, int w, int f) {
    return (w * x) + (f * x) >= k; 
 }
 
 
void solve() {
    int w, f; cin >> w >> f;
    int n; cin >> n;
    vector<int> V;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int tmp; 
        cin >> tmp; 
        sum += tmp;
        V.push_back(tmp);
    }
    int l = 0, r = 1e6;
    while(l < r) {
        int mid = l + (r - l) / 2;
        if (canKillAllMonster(mid, sum, w, f)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << l << endl;
}
 
 
signed main() {
    fast;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
 
    int t; cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}