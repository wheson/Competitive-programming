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

    int n, w;
    cin >> n >> w;
    vector<int> wei(n), val(n);
    REP(i, n) cin >> wei[i] >> val[i];

    vector<vector<LL>> dp(n+1, vector<LL>(w+1, 0));
    REP(i, n){
        REP(j, w+1){
            dp[i+1][j] = max(dp[i][j], (wei[i] <= j ? dp[i][j-wei[i]] + val[i] : 0));
        }
    }
    cout << dp[n][w] << endl;
}