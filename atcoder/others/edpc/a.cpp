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

    int n;
    cin >> n;
    vector<int> h(n);
    REP(i, n) cin >> h[i];

    vector<int> dp(n+5, INF);

    dp[0] = 0;
    REP(i, n) {
        dp[i + 1] = min(dp[i] + abs(h[i + 1] - h[i]), dp[i + 1]);
        dp[i + 2] = min(dp[i] + abs(h[i + 2] - h[i]), dp[i + 2]);
    }
    cout << dp[n-1] << endl;
}