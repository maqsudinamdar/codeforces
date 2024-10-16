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


const int N = 1e5+10;
int tree[4 * N + 1];


void build(int idx, int tl, int tr, vector<int>& a) {
    if (tl == tr) {
        tree[idx] = a[tl];
        return;
    }
    int tm = (tl + tr) / 2;
    build(2 * idx, tl, tm, a);
    build(2 * idx + 1, tm + 1, tr, a);
    tree[idx] = tree[2 * idx] ^ tree[2 * idx + 1];
}


int exor_query(int idx, int tl, int tr, int l, int r, vector<int>& a) {
    if (tl > r || tr < l) {
        return 0;
    }
    if (tl >= l && tr <= r) {
        return tree[idx];
    }
    int tm = (tl + tr) / 2;
    int left_exor_query = exor_query(2 * idx, tl, tm, l, r, a);
    int right_exor_query = exor_query(2 * idx + 1, tm + 1, tr, l, r, a);
    return left_exor_query ^ right_exor_query;
}



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
        memset(tree, 0, 4 * n + 1);
        for (int i = 0; i < n; i++) cin >> a[i];
        string binary_string; cin >> binary_string;
        vector<int> ans(2);
        for (int i = 0; i < n; i++) {
            if (binary_string[i] == '1') {
                ans[1] ^= a[i];
            } else {
                ans[0] ^= a[i];
            }
        }
        build(1, 0, n - 1, a);
        int q; cin >> q;
        while (q--) {
            int type; cin >> type;
            if (type == 1) {
                int l, r; cin >> l >> r;
                l--; r--;
                int query = exor_query(1, 0, n - 1, l, r, a);
                ans[0] ^= query;
                ans[1] ^= query;
            } else {
                int g; cin >> g;
                cout << ans[g] << " ";
            }
           
        }
        cout << "\n";
    }
    return 0;
}
