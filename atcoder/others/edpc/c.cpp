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
    vector<int> a(n), b(n), c(n);
    REP(i, n) cin >> a[i] >> b[i] >> c[i];

    vector<vector<int>> dp(n+1, vector<int>(3, 0));
    REP(i, n){
        dp[i+1][0] = max(dp[i][1] + a[i], dp[i][2] + a[i]);
        dp[i+1][1] = max(dp[i][0] + b[i], dp[i][2] + b[i]);
        dp[i+1][2] = max(dp[i][0] + c[i], dp[i][1] + c[i]);
    }
    cout << max({dp[n][0], dp[n][1], dp[n][2]}) << endl;
}