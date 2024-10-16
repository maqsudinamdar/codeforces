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
        int n; 
        cin >> n;
        string s; cin >> s;
        string newStr;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                newStr += s[i];
            } else {
                newStr += s[i];
                while (s[i] == '0') {
                    i++;
                }
                i--;
            }
        }
        // cout << newStr << endl;
        int cnt_1 = 0, cnt_0 = 0;
        for (char c: newStr) {
            
            if (c == '1') {
                // cout << c << endl;
                cnt_1++;
            } else {
                cnt_0++;
            }
        }

        if (cnt_1 > cnt_0) {
            cout << "YES"; 
        } else {
            cout << "NO";
        }
        cout << "\n";
    }
    return 0;
}
