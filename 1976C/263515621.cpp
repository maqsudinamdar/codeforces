#include <bits/stdc++.h>
#define xx first
#define yy second
#define sz(x) ((ll) (x).size())
#define all(x) (x).begin(), (x).end()
#define mod(a, b) ((((a) % (b)) + (b)) % (b))
using namespace std;
typedef long long ll;
const ll INF = (1LL << 62);

ll calc_gpc(ll mid, ll i, vector<ll> A, vector<ll> B, vector<ll> cum_good_p) {
    return cum_good_p[mid + 1] - (i <= mid && A[i] > B[i]);
}

void solve() {
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N + M + 1);
    for(auto &x : A)
        cin >> x;
    vector<ll> B(N + M + 1);
    for(auto &x : B)
        cin >> x;
    vector<ll> cum_cherry_picking(N + M + 2, 0);
    vector<ll> cum_p_skills(N + M + 2, 0);
    vector<ll> cum_t_skills(N + M + 2, 0);
    vector<ll> cum_good_p(N + M + 2, 0);
    vector<ll> cum_good_t(N + M + 2, 0);
    for(ll i = 0; i < N + M + 1; i++) {
        cum_cherry_picking[i + 1] = cum_cherry_picking[i] + max(A[i], B[i]);
        cum_p_skills[i + 1] = cum_p_skills[i] + A[i];
        cum_t_skills[i + 1] = cum_t_skills[i] + B[i];
        cum_good_p[i + 1] = cum_good_p[i] + (A[i] > B[i]);
        cum_good_t[i + 1] = cum_good_t[i] + (A[i] < B[i]);
    }
    for(ll i = 0; i < N + M + 1; i++) {
        // auto calc_gpc = [&](ll mid) -> ll {
        //     return cum_good_p[mid + 1] - (i <= mid && A[i] > B[i]);
        // };
        ll lo = -1;
        ll hi = N + M + 1;
        while(lo + 1 < hi) {
            ll mid = (lo + hi) / 2;
            ll gpc = calc_gpc(mid, i, A, B, cum_good_p);
            ll gtc = cum_good_t[mid + 1] - (i <= mid && A[i] < B[i]);
            if(gpc <= N && gtc <= M)
                lo = mid;
            else
                hi = mid;
        }
        bool no_more_p = calc_gpc(lo, i, A, B, cum_good_p) == N;
        ll ans = cum_cherry_picking[lo + 1] + (no_more_p ? (cum_t_skills[N + M + 1] - cum_t_skills[lo + 1]) : (cum_p_skills[N + M + 1] - cum_p_skills[lo + 1]));
        if(i <= lo)
            ans -= max(A[i], B[i]);
        else
            ans -= (no_more_p ? B[i] : A[i]);
        cout << ans << ' ';
    }
    cout << '\n';
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ll T;
    cin >> T;
    while(T--)
        solve();
    return 0;
}
 