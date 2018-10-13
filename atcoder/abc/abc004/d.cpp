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

    int r, g, b;
    cin >> r >> g >> b;

    vector<int> rbox(1000, 0), gbox(1000, 0), bbox(1000, 0);
    REP(i, 1000){
        rbox[i] = abs(400 - i);
        gbox[i] = abs(500 - i);
        bbox[i] = abs(600 - i);
    }
    
    vector<vector<int>> dp(1001, vector<int>(r+g+b+1, INF));
    dp[0][0] = 0;

    REP(i, 1000){
        REP(j, r+g+b){
            dp[i+1][j] = min(dp[i+1][j], dp[i][j] + )
        }
    }

    cout << dp[1000][r+g+b] << endl;
}
