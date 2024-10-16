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


int helper(int row, int start_idx, int required_sum, vector<vector<int > > & arr) {
    int l = start_idx + 1, r = arr[0].size() - 1, mid, ans = -1;
    while (l <= r) {
        mid = (l + r) / 2;
        int sum = arr[row][mid] - arr[row][start_idx];
        if (sum >= required_sum) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return ans;
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
        vector<vector<int > > arr(3, vector<int>(n + 1, 0));
        int tmp;
        for (int i = 0; i < 3; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> tmp;
                arr[i][j] = tmp + arr[i][j - 1];
            }
        }

        int required_sum = ceil(arr[0][n] / 3);
        if (arr[0][n] % 3 != 0) required_sum++;
        bool is_ans_found = false;
        for (int i = 0; i < 3; i++) {
            int i_th_start_idx = 0;
            int i_th_end_idx = helper(i, i_th_start_idx, required_sum, arr);
            if (i_th_end_idx == -1) {
                continue;
            }
            for (int j = 0; j < 3; j++) {
                if (i != j) {
                    int j_th_start_idx = i_th_end_idx;
                    int j_th_end_idx = helper(j, j_th_start_idx, required_sum, arr);
                    if (j_th_end_idx == -1) {
                        continue;
                    }
                    for (int k = 0; k < 3; k++) {
                        if (k != i && k != j) {
                            int k_th_start_idx = j_th_end_idx;
                            int k_th_end_idx = helper(k, k_th_start_idx, required_sum, arr);
                            if (k_th_end_idx == -1) {
                                continue;
                            } else {
                                k_th_end_idx = n;
                                for (int p = 0; p < 3; p++) {
                                    is_ans_found = true;
                                    if (p == i) {
                                        cout << i_th_start_idx + 1 << " " << i_th_end_idx << " ";
                                    } else if (p == j) {
                                        cout << j_th_start_idx + 1 << " " << j_th_end_idx << " ";
                                    } else if (p == k) {
                                        cout << k_th_start_idx + 1 << " " << k_th_end_idx << " ";
                                    } 
                                }
                                cout << endl;
                            }
                        }
                        if (is_ans_found) break;
                    }
                    if (is_ans_found) break;
                }
                if (is_ans_found) break;
            }
        }
        if (!is_ans_found) {
            cout << -1 << endl;
        }
        
        
    }
    return 0;
}
