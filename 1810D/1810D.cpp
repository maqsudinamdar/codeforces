/**
 *    author:  maq5ud     
**/
#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endl                '\n'
#define ll                 long long
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

ll intersect(ll L, ll R, ll _L, ll _R){
    return max(0LL, min(_R, R) - max(L, _L) + 1);
}

ll findDays(ll H, int a, int b) {
    ll l = 2, r = H /(a-b) + 1, mid;

    int n = r;
    if (a >= H) return 1;
    while (l < r) {
        mid = (l + r) / 2;
        if (H <= (mid - 1) * (a - b) + a) {
            n = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return n;
}
 

signed main() {
    fast;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
 
    int t; cin>>t;
    while(t--) {
        int q; cin >>  q;
        ll L = 1, R = 1e18;
        while (q--) {
            int e; cin >> e;
            int a, b;
            if (e == 1) {
                int n; cin >> a >> b >> n;
                ll _L = (n - 2) * (a - b) + a + 1;
                ll _R = (n - 1) * (a - b) + a;
                if (n == 1) {
                    _L = 1, _R = a;
                }
                if (!intersect(L, R, _L, _R)) {
                    cout << "0 "; 
                } else {
                    cout << "1 ";
                    L = max(L, _L);
                    R = min(R, _R);
                }
            } else if (e == 2) {
                cin >> a >> b;
                int NL = findDays(L, a, b), NR = findDays(R, a, b);
                if (NL == NR) {
                    cout << NL << " ";
                } else {
                    cout << "-1 ";
                }
            }
        }
        cout << endl;
    }
    return 0;
}