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

    const string y = "yahoo";

    string s;
    cin >> s;

    int dp[100005][5];
    REP(i, s.size()+1) REP(j, 5) dp[i][j] = INF;
    REP(i, s.size()+1) dp[i][0] = i;
    REP(i, 5) dp[0][i] = i;

    REP(i, s.size()){
        REP(j, 10){
            dp[i+1][(j+1)%5] = min(dp[i+1][(j+1)%5], dp[i][(j+1)%5] + 1);
            dp[i+1][(j+1)%5] = min(dp[i+1][(j+1)%5], dp[i+1][j%5] + 1);

            if(s[i] == y[j%5]){
                dp[i+1][(j+1)%5] = min(dp[i+1][(j+1)%5], dp[i][j%5]);
            }else{
                dp[i+1][(j+1)%5] = min(dp[i+1][(j+1)%5], dp[i][j%5] + 1);
            }
        }
    }

    cout << dp[s.size()][0];
}