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

    int h, w, k;
    cin >> h >> w >> k;

    vector<vector<LL>> dp(h+1, vector<LL>(w));
    dp[0][0] = 1;
    REP(i, h){
        for(int mask = 0; mask < (1 << (w-1)); mask++){
            bool isRinsetsu = false;
            REP(j, w-1){
                if(mask & (1 << j) && mask & (2 << j)) isRinsetsu = true;
            }
            if(isRinsetsu) continue;
            
            REP(j, w){
                if(j < w-1 && mask & (1 << j)) (dp[i+1][j+1] += dp[i][j]) %= MOD;
                else if(j > 0 && mask & (1 << (j-1))) (dp[i+1][j-1] += dp[i][j]) %= MOD;
                else (dp[i+1][j] += dp[i][j]) %= MOD;
            }
        }
    }
    cout << dp[h][k-1] << endl;
}