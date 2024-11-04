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

int recursion(int i, bool flag, int sum, vector<int> &a) {
    if (i >= a.size()) return 0;
    if (a[i] == 0) {
        int pick = 1 + recursion(i + 1, false, 0, a);
        return pick;
    } else {
        if (flag) {
            if (sum + a[i] == 0) {
                int notPick = 1 + recursion(i + 1, false, 0, a);
                return notPick;
            } else {
                int pick = recursion(i + 1, true, sum + a[i], a);
                return pick;
            }
        } else {
            int pick = recursion(i + 1, true, sum + a[i], a);
            int notPick = recursion(i + 1, false, 0, a);
            return max(pick, notPick);
        }
    }
}   


int memoization(int i, bool flag, int sum, vector<int> &a, vector<vector<int > > &dp) {
    if (i >= a.size()) return 0;
    if (dp[i][flag] != -1) return dp[i][flag];
    int ans = 0;
    if (a[i] == 0) {
        int pick = 1 + memoization(i + 1, false, 0, a, dp);
        ans = pick;
    } else {
        if (flag) {
            if (sum + a[i] == 0) {
                int notPick = 1 + memoization(i + 1, false, 0, a, dp);
                ans = notPick;
            } else {
                int pick = memoization(i + 1, true, sum + a[i], a, dp);
                ans = pick;
            }
        } else {
            int notPick = memoization(i + 1, false, 0, a, dp);
            int pick = memoization(i + 1, true, sum + a[i], a, dp);
            ans = max(pick, notPick);
        }
    }
    return dp[i][flag] = ans;
}  


int bruteForceApproach(int n, vector<int> &a) {
    int k = 0;
    int subSumEqualToKCount = 0;
    for (int i = 0; i < n; i++) {
        int sum = a[i];
        if (sum == k) {
            subSumEqualToKCount++;
        } else {
            for (int j = i + 1; j < n; j++) {
                sum += a[j];
                if (sum == k) {
                    subSumEqualToKCount++;
                    i = j;
                    break;
                }
            }
        }
    }
    return subSumEqualToKCount;
}


int prefixSum(int n, vector<int> &a) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 0) {
            cnt++;
        } else {
            set<int> st;
            st.insert(0);
            int prefix_sum = 0;
            while(i < n) {
                prefix_sum += a[i];
                if (st.find(prefix_sum) != st.end()) {
                    cnt++;
                    break;
                }
                st.insert(prefix_sum);
                i++;
            }
        }
    }
    return cnt;
}


int solve(int n, vector<int> &a) {
    return prefixSum(n, a);
    // return recursion(0, false, 0, a);

    vector<vector<int > > dp(n, vector<int>(2, -1));
    return memoization(0, false, 0, a, dp);
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
        vector<int> a(n); for (int i = 0; i < n; i++) cin >> a[i];
        int ans = solve(n, a);
        cout << ans;
        cout << "\n";
    }
    return 0;
}
