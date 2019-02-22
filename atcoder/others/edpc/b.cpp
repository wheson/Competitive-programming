#include <bits/stdc++.h>
//#define int long long

using namespace std;
using LL = long long;

#define FOR(i, a, n) for(int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)

#define pb(a) push_back(a)
#define all(x) (x).begin(),(x).end()

const int INF = (int)1e9;
const LL INFL = (LL)1e19;
const int MOD = (int)1e9 + 7;

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    vector<int> h(n);
    REP(i, n) cin >> h[i];

    vector<int> dp(n+105, INF);

    dp[0] = 0;
    REP(i, n) {
        REP(j, k) {
            dp[i + j + 1] = min(dp[i] + abs(h[i + j + 1] - h[i]), dp[i + j + 1]);
        }
    }
    cout << dp[n-1] << endl;
}