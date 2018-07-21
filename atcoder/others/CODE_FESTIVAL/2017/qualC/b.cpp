#include <bits/stdc++.h>
//#define int long long

using namespace std;
using LL = long long;
using P = pair<int, int>;

#define FOR(i, a, n) for(int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)

#define pb(a) push_back(a)
#define all(x) (x).begin(),(x).end()

const int INF = (int)1e9;
const LL INFL = (LL)1e18;
const int MOD = 1e9 + 7;

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n);
    REP(i, n) cin >> a[i];

    int dp[15][2];
    dp[0][0] = 1, dp[0][1] = 0;
    REP(i, n){
        if(a[i] & 1){
            dp[i+1][0] = dp[i][0];
            dp[i+1][1] = dp[i][0] * 2 + dp[i][1] * 3;
        }else{
            dp[i+1][0] = dp[i][0] * 2;
            dp[i+1][1] = dp[i][1] * 3 + dp[i][0] * 1;
        }
    }
    cout << dp[n][1] << endl;
}
