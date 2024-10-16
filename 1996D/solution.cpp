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


int get_c_from_product_sum(int a, int b, int n) {
    return (n - (a * b)) / (a + b);
}

int get_c_from_sum(int a, int b, int x) {
    return (x - a - b);
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
        int cnt = 0;
        for (int a = 1; a <= n; a++) {
            for (int b = 1; a * b <= n and a + b <= x; b++) {
                int i = get_c_from_product_sum(a, b, n);
                int j = get_c_from_sum(a, b, x);
                int c = min(i, j);
                cnt += c;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}
