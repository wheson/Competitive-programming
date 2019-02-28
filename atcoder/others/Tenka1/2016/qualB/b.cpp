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
const int MOD = (int)1e9 + 7;


signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;

    // i番目まで見ていて最後の変更がjで
    int dp[105][105][105];
    REP(i, s.size()+1)
        REP(j, s.size()+1)
            REP(k, s.size()+1)
                dp[i][j][k] = INF;

    dp[0][0][0] = 0;
     REP(i, s.size())
        REP(j, s.size())
            REP(k, s.size()+1)
                if(dp[i][j][k] != INF){

         if(s[i] == '('){
             dp[i+1][j][k+1] = min(dp[i+1][j][k+1], dp[i][j][k]);
             if(k > 0) dp[i+1][i][k-1] = min(dp[i+1][i][k-1], dp[i][j][k] + 1);
         }else{
             dp[i+1][i][k+1] = min(dp[i+1][i][k+1], dp[i][j][k] + 1);
             if(k > 0) dp[i+1][j][k-1] = min(dp[i+1][j][k-1], dp[i][j][k]);
         }
     }

     int ans = INF;
     REP(j, s.size()) ans = min(ans, dp[s.size()][j][0] + j);

     cout << ans << endl;

}