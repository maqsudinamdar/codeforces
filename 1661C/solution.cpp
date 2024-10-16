/**
 *    author:  maq5ud     
**/
#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endl                '\n'
#define ll                  long long
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
 
bool isValid(ll days, ll maxi, vector<ll>& a) {
    ll no_of_odd_days = 0, no_of_even_days = 0;
    no_of_odd_days = days / 2;
    if (days % 2 != 0)  no_of_odd_days++;
    if (days > 1) no_of_even_days = days / 2;
    // cout << " -- " << endl;
    // cout << days << " " << no_of_odd_days << " " << no_of_even_days << endl;
    
    for (int i = 0; i < a.size(); i++) {
        if (a[i] < maxi) {
            ll diff = maxi - a[i];
            if (diff % 2 != 0) {
                diff--;
                no_of_odd_days--;
                if (no_of_odd_days < 0) return false; 
            }
            if (diff && no_of_even_days) {
                ll required_even_no_of_days = (diff / 2);
                if (required_even_no_of_days > no_of_even_days) {
                    diff = (required_even_no_of_days - no_of_even_days)*2;
                    no_of_even_days = 0;
                } else {
                    no_of_even_days -= (diff / 2);
                    diff = 0;
                }
            } 
            if (diff) {
                ll required_odd_no_of_days = diff;
                if (required_odd_no_of_days > no_of_odd_days) {
                    return false;
                } else {
                    no_of_odd_days -= diff;
                    diff = 0;
                }
            }
            // if (no_of_even_days < 0 || no_of_odd_days < 0) {
            //     return false;
            // }
            // cout << "i: " << i << " d: " << diff << " " << " e " << no_of_even_days << " o " << no_of_odd_days << " ";
        }
        // cout << endl;
    }
    return true;
}

signed main() {
    fast;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t; cin>>t;
    while(t--) {
        int n; cin >> n;
        vector<ll> a(n);
        ll maxi = LLONG_MIN;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            maxi = max(maxi, a[i]);
        }
        // sort(a.begin(), a.end());
        ll l = 0, r = LLONG_MAX, mid;
        ll max_ans;
        while(l <= r) {
            mid = l + (r - l) / 2;
            // cout << "m " << mid << endl;
            if (isValid(mid, maxi, a)) {
                max_ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }                      
        }

        l = 0, r = LLONG_MAX, mid;
        ll max_plus_1_ans;
        while(l <= r) {
            mid = l + (r - l) / 2;
            // cout << "m " << mid << endl;
            if (isValid(mid, maxi + 1, a)) {
                max_plus_1_ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }                      
        }
        
        cout << min(max_ans, max_plus_1_ans) << endl;
    }
    return 0;
}