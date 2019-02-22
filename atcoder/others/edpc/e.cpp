#include <bits/stdc++.h>
//#define int long long

using namespace std;
using LL = long long;

#define FOR(i, a, n) for(int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)

#define pb(a) push_back(a)
#define all(x) (x).begin(),(x).end()

const int INF = (int)1e9;
const LL INFL = (LL)1e18;
const int MOD = (int)1e9 + 7;

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, w;
    cin >> n >> w;

    vector<int> wei(n), val(n);
    REP(i, n) cin >> wei[i] >> val[i];

    vector<vector<LL>> dp(n+1, vector<LL>(100005, INFL));
    dp[0][0] = 0;
    REP(i, n){
        REP(j, 100005){
            if(val[i] <= j && dp[i][j - val[i]] + wei[i] <= w){
                dp[i+1][j] = min(dp[i][j], dp[i][j-val[i]] + wei[i]);
            }else{
                dp[i+1][j] = dp[i][j];
            }
        }
    }

    int ans = 0;
    REP(i, 100001) if(dp[n][i] != INFL) ans = i;

    cout << ans << endl;
}