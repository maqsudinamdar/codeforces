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


double calcEucDist(int x, int y) {
    double a = pow(x, 2); // log(x)
    double b = pow(y, 2); // log(y)
    double c = a + b;
    double d = sqrt(c); // log(c)
    return d;
}


bool check(int x, int r) {
    double d = calcEucDist(x, r);
    return d < (double) r + 1;
}



signed main() {
    fast;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t; cin>>t;
    while(t--) {
        int r; cin >> r;
        int h = r;
        for (; h >= 0; h--) {
            double d = calcEucDist(0, h);
            if (d < r + 1) {
                break;
            }
        }
        int ans = 0;
        for (int i = 90)
    }
    return 0;
}