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
    vector<double> p(n);
    REP(i, n) cin >> p[i];

    vector<vector<double>> dp(n+1, vector<double>(n+1, 0));
    dp[0][0] = 1;
    REP(i, n){
        REP(j, i+1){
            dp[i+1][j+1] = dp[i][j] * p[i] + dp[i][j+1] * (1 - p[i]);

        }
    }

    double ans = 0;
    FOR(j, n/2 + 1, n+1) ans += dp[n][j];
    printf("%.9f\n", ans);
}