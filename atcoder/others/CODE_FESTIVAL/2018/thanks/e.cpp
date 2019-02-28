#include <bits/stdc++.h>
#define int long long

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

    int t;
    cin >> t;
    vector<int> a(t);
    REP(i, t) cin >> a[i];

    LL dp[305][1005] = {0};
    dp[0][0] = 1;

    LL ans = 0;
    REP(i, t){
        REP(j, 500){
            REP(k, a[i]+1){
                (dp[i+1][j+k] += dp[i][2*j]) %= MOD;
            }
        }
        (ans += dp[i+1][1]) %= MOD;
    }


    for (int j = 2; j < 1000; j *= 2) {
        (ans += dp[t][j]) %= MOD;
    }

    cout << ans << endl;
}