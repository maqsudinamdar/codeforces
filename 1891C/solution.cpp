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
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        int i = 0, j = n - 1;
        int power = 0, attack = 0;
        while (i <= j) {
            if (i == j) {
                if (a[j] == 1) {
                    attack++;
                } else {
                    attack += 1 + max(0LL, (a[j] - power + 1) / 2);
                }
                break;
            } 
            int d = min(a[i], a[j] - power);
            a[i] -= d;
            power += d;
            attack += d;
            if (a[i] == 0) {
                i++;
            } else if (a[j] == power) {
                j--;
                attack++; 
                power = 0;
            }
        }
        cout << attack;
        cout << "\n";
    }
    return 0;
}
