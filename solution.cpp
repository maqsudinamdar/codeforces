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



signed main() {
    fast;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
 
    int t; cin>>t;
    while(t--) {
        int N, M, K, D;
        cin >> N >> M >> K >> D;
        vector<vector<int> > a(N, vector<int>(M));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> a[i][j];
            }
        }
        vector<int> b(N);
        for (int i = 0; i < N; i++) {
            vector<int> dp(M);
            multiset<int> mst;
            mst.insert(1);
            dp[0] = 1;
            for (int j = 1; j < M - 1; j++) {
                dp[j] = *mst.begin() + a[i][j] + 1;
                if (j - D - 1 >= 0) {
                    mst.erase(mst.find(dp[j - D - 1]));
                }
                mst.insert(dp[j]);
            }
            dp[M - 1] = *mst.begin() + 1;
            b[i] = dp[M - 1];
        }
        int sum = 0;
        for (int i = 0; i < K; i++) {
            sum += b[i];
        }
        int ans = sum;
        int prev_sum = sum;
        for (int i = K; i < N; i++) {
            prev_sum += b[i] - b[i - K];
            ans = min(ans, prev_sum);
        }
        cout << ans << endl;
    }
    return 0;
}