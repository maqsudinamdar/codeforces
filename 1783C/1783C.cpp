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
 
int get_win(int idx, int m, vector<int>& a) {
    int idx_win = idx;
    if (a[idx] > m) {
        idx_win++;
    }
    return idx_win;
}

int get_rank(int idx, int n, int m, vector<int>& a) {
    int rank = 1;
    for (int j = n - 2; j >= idx; j--) {
        int j_win = get_win(j, m, a);
        int j_1_win = get_win(j + 1, m, a);
        if (j_win != j_1_win) {
            rank++;
        }
    }
    return rank;
}

signed main() {
    fast;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
 
    int t; cin>>t;
    while(t--) {
        int n, m; cin >> n >> m;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        auto b = a;
        sort(b.begin(), b.end());
        int idx = 0;
        for (int i = 0; i < n && b[i] <= m; i++) {
            m -= b[i];
            idx++;
        }
        if (idx && idx != n && m + b[idx - 1] >= a[idx]) {
            idx++;
        }
        cout << (n - idx + 1) << endl;
    }
    return 0;
}