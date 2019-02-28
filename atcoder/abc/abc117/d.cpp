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

    LL n, k;
    cin >> n >> k;
    vector<LL> a(n);
    REP(i, n) cin >> a[i];

    vector<LL> b(45), c(45);
    REP(i, 45){
        REP(j, n) b[i] += (a[j] & (1LL << i)) xor (1LL << i);
        REP(j, n) c[i] += (a[j] & (1LL << i)) xor 0LL;
    }

    vector<vector<LL>> dp(50, vector<LL>(2, -1));
    dp[45][0] = 0;

    for (int i = 44; i >= 0; i--) {
        LL mask = (1LL << i);
        if(dp[i+1][1] >= 0){
            dp[i][1] = max(dp[i][1], dp[i+1][1] + max(b[i], c[i]));
        }
        if(dp[i+1][0] >= 0){
            if(k & mask){
                dp[i][0] = max(dp[i][0], dp[i+1][0] + b[i]);
                dp[i][1] = max(dp[i][1], dp[i+1][0] + c[i]);
            }else{
                dp[i][0] = max(dp[i][0], dp[i+1][0] + c[i]);
            }
        }
    }

    cout << max(dp[0][0], dp[0][1]) << endl;
}