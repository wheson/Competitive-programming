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
int n;
P m;
vector<int> a, b, c;
int dp[45][405][405];
/**********************************************/

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin >> n;
    cin >> m.first >> m.second;

    a.resize(n);
    b.resize(n);
    c.resize(n);

    REP(i, n) cin >> a[i] >> b[i] >> c[i];
    REP(i, n+1){
        REP(j, 401){
            REP(k, 401){
                dp[i][j][k] = INF;
            }
        }
    }
    dp[0][0][0] = 0;
    REP(i, n){
        REP(j, 401){
            REP(k, 401){
                if(dp[i][j][k] == INF) continue;
                
                dp[i+1][j][k] = min(dp[i+1][j][k], dp[i][j][k]);
                dp[i+1][j+a[i]][k+b[i]] = min(dp[i+1][j+a[i]][k+b[i]], dp[i][j][k] + c[i]);
                
            }
        }
    }
    int ans = INF;
    FOR(j, 1, 401){
        FOR(k, 1, 401){
            if(j*m.second == k*m.first) ans = min(ans, dp[n][j][k]);
        }
    }

    if(ans != INF) cout << ans << endl;
    else cout << -1 << endl;

}
