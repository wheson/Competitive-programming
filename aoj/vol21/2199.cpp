#include <bits/stdc++.h>

using namespace std;
using LL = long long;
using P = pair<int, int>;
using Tapris = tuple<int, int, int>;

#define REP(i, n) for(LL i = 0; i < n; ++i)
#define FOR(i, a, n) for(LL i = a; i < n; ++i)
#define pb(a) push_back(a)
#define all(x) (x).begin(),(x).end()

const int INF = (int)1e9;
const LL INFL = (LL)1e15;
const int MOD = 1e9 + 7;

int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

//#define int long long

/*************** using variables ***************/
int n, m;
vector<int> c, x;
LL dp[20005][256];
/**********************************************/

signed main(){
    while(cin >> n >> m, n != 0 || m != 0){
        c.resize(m);
        x.resize(n);
        REP(i, m) cin >> c[i];
        REP(i, n) cin >> x[i];

        REP(i, 20005) REP(j, 256) dp[i][j] = INF;
        dp[0][128] = 0;
        FOR(i, 1, n+1){
            for(int j = 0; j <= 255; j++){
                bool flag = false;
                if(j == 0){
                    REP(k, m){
                        for(int z = 0 - c[k]; z >= 0; z--){
                            if(dp[i-1][z] != INF){
                                dp[i][0] = min(dp[i][0], dp[i-1][z] + (LL)pow(abs(x[i-1] - (0)), 2));
                            }
                        }
                    }
                }else if(j == 255){
                    REP(k, m){
                        for(int z = 255 - c[k]; z <= 255; z++){
                            if(dp[i-1][z] != INF){
                                dp[i][255] = min(dp[i][255], dp[i-1][z] + (LL)pow(abs(x[i-1] - (255)), 2));
                            }
                        }
                    }
                }else{
                    REP(k, m) flag |= dp[i-1][j-c[k]] != INF;
                    if(flag){
                        REP(k, m){
                            if(j-c[k] >= 0 && j-c[k] <= 255 && dp[i-1][j-c[k]] != INF){
                                dp[i][j] = min(dp[i][j], dp[i-1][j-c[k]] + (LL)pow(abs(x[i-1] - j), 2));
                                //cout << i << " " << dp[i][j] << " " << x[i-1] << " " << j-c[k] << endl;
                            }
                        }
                    }
                }
            }
        }

        LL ans = INF;
        for(int i = 0; i <= 255; i++) ans = min(ans, dp[n][i]);
        cout << ans << endl;
    }

}
