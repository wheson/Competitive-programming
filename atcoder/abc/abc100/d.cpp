#include <bits/stdc++.h>
#define int long long

using namespace std;
using LL = long long;
using P = pair<int, int>;

#define FOR(i, a, n) for(int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)

#define pb(a) push_back(a)
#define all(x) (x).begin(),(x).end()

const int INF = (int)1e9;
const LL INFL = (LL)1e15;
const int MOD = 1e9 + 7;

int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

LL dp[8][1050][1050];

signed main(){
    
    int n, m;
    cin >> n >> m;
    vector<LL> x(n), y(n), z(n);
    REP(i, n) cin >> x[i] >> y[i] >> z[i];
    REP(k, 8) REP(i, 1050) REP(j, 1050) dp[k][i][j] = 0LL;

    REP(i, n){
        REP(j, i+1){
            if(j != i) dp[0][i+1][j+1] = max(dp[0][i][j+1], dp[0][i][j] + x[i] + y[i] + z[i]);
            else dp[0][i+1][j+1] = dp[0][i][j] + x[i] + y[i] + z[i];
        }
    }

    REP(i, n){
        REP(j, i+1){
            if(j != i) dp[1][i+1][j+1] = max(dp[1][i][j+1], dp[1][i][j] - x[i] + y[i] + z[i]);
            else dp[1][i+1][j+1] = dp[1][i][j] - x[i] + y[i] + z[i];
        }
    }

    REP(i, n){
        REP(j, i+1){
            if(j != i) dp[2][i+1][j+1] = max(dp[2][i][j+1], dp[2][i][j] + x[i] - y[i] + z[i]);
            else dp[2][i+1][j+1] = dp[2][i][j] + x[i] - y[i] + z[i];
        }
    }

    REP(i, n){
        REP(j, i+1){
            if(j != i) dp[3][i+1][j+1] = max(dp[3][i][j+1], dp[3][i][j] + x[i] + y[i] - z[i]);
            else dp[3][i+1][j+1] = dp[3][i][j] + x[i] + y[i] - z[i];
        }
    }

    REP(i, n){
        REP(j, i+1){
            if(j != i) dp[4][i+1][j+1] = max(dp[4][i][j+1], dp[4][i][j] - x[i] - y[i] + z[i]);
            else dp[4][i+1][j+1] = dp[4][i][j] - x[i] - y[i] + z[i];
        }
    }

    REP(i, n){
        REP(j, i+1){
            if(j != i) dp[5][i+1][j+1] = max(dp[5][i][j+1], dp[5][i][j] - x[i] + y[i] - z[i]);
            else dp[5][i+1][j+1] = dp[5][i][j] - x[i] + y[i] - z[i];
        }
    }

    REP(i, n){
        REP(j, i+1){
            if(j != i) dp[6][i+1][j+1] = max(dp[6][i][j+1], dp[6][i][j] + x[i] - y[i] - z[i]);
            else dp[6][i+1][j+1] = dp[6][i][j] + x[i] - y[i] - z[i];
        }
    }

    REP(i, n){
        REP(j, i+1){
            if(j != i) dp[7][i+1][j+1] = max(dp[7][i][j+1], dp[7][i][j] - x[i] - y[i] - z[i]);
            else dp[7][i+1][j+1] = dp[7][i][j] - x[i] - y[i] - z[i];
        }
    }

    LL ans = 0;
    REP(i, 8) ans = max(ans, dp[i][n][m]);
    
    cout << ans << endl;
}
