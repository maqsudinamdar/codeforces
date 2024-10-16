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

int 


void solve() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N + M + 1);
    for(auto &x : A)
        cin >> x;
    vector<int> B(N + M + 1);
    for(auto &x : B)
        cin >> x;
    vector<int> cum_cherry_picking(N + M + 2, 0);
    vector<int> cum_p_skills(N + M + 2, 0);
    vector<int> cum_t_skills(N + M + 2, 0);
    vector<int> cum_good_p(N + M + 2, 0);
    vector<int> cum_good_t(N + M + 2, 0);
    for(int i = 0; i < N + M + 1; i++) {
        cum_cherry_picking[i + 1] = cum_cherry_picking[i] + max(A[i], B[i]);
        cum_p_skills[i + 1] = cum_p_skills[i] + A[i];
        cum_t_skills[i + 1] = cum_t_skills[i] + B[i];
        cum_good_p[i + 1] = cum_good_p[i] + (A[i] > B[i]);
        cum_good_t[i + 1] = cum_good_t[i] + (A[i] < B[i]);
    }
    for(int i = 0; i < N + M + 1; i++) {
        auto calc_gpc = [&](int mid) -> int {
            return cum_good_p[mid + 1] - (i <= mid && A[i] > B[i]);
        };
        int lo = -1;
        int hi = N + M + 1;
        while(lo + 1 < hi) {
            int mid = (lo + hi) / 2;
            int gpc = calc_gpc(mid);
            int gtc = cum_good_t[mid + 1] - (i <= mid && A[i] < B[i]);
            if(gpc <= N && gtc <= M)
                lo = mid;
            else
                hi = mid;
        }
        bool no_more_p = calc_gpc(lo) == N;
        int ans = cum_cherry_picking[lo + 1] + (no_more_p ? (cum_t_skills[N + M + 1] - cum_t_skills[lo + 1]) : (cum_p_skills[N + M + 1] - cum_p_skills[lo + 1]));
        if(i <= lo)
            ans -= max(A[i], B[i]);
        else
            ans -= (no_more_p ? B[i] : A[i]);
        cout << ans << ' ';
    }
    cout << '\n';
}


signed main() {
    fast;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t; cin >> t;
    while(t--) {
        solve();
        // int n, m; cin >> n >> m;
        // vector<int> p(n + m + 1), t(n + m + 1);
        // for (int i = 0; i < (n + m + 1); i++) cin >> p[i];
        // for (int i = 0; i < (n + m + 1); i++) cin >> t[i];

        // vector<int> lP(n + m + 1, -1), rP(n + m + 1, -1), lT(n + m + 1, -1), rT(n + m + 1, -1), total(n + m + 1, 0);

        // for (int i = 1; i < (n + m + 1); i++) {
        //     lP[i] = i;
        //     if ( p[lP[i]] < p[lP[i - 1]]  ) {
        //         lP[i] = i - 1;
        //     }
        //     lT[i] = i;
        //     if ( t[lT[i]] < t[lT[i - 1]]  ) {
        //         lT[i] = i - 1;
        //     }
        // }

        // for (int i = (n + m + 1) - 2; i >= 0; i--) {
        //     rP[i] = i;
        //     if ( p[rP[i]] < p[rP[i + 1]]  ) {
        //         rP[i] = i + 1;
        //     }
        //     rT[i] = i;
        //     if ( t[rT[i]] < t[rT[i + 1]]  ) {
        //         rT[i] = i + 1;
        //     }  
        // }
        // total[0] = p[0] + t[0];
        // for (int i = 1; i < (n + m + 1); i++) {
        //     total[i] += total[i - 1] + p[i] + t[i];
        // }

        
    }
    return 0;
}