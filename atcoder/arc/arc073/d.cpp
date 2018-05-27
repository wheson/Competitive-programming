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
const LL INFL = (LL)1e15;
const int MOD = 1e9 + 7;

int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

/*************** using variables **************/
int N, W;
vector<int> w, v;
int w0;
int dp[105][105][500*4+5];
/**********************************************/

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> W;
    w.resize(N);
    v.resize(N);
    REP(i, N) cin >> w[i] >> v[i];
    w0 = w[0];
    REP(i, N) w[i] -= w0;
    
    REP(i, 105) REP(j, 105) REP(k, 200*4+5) dp[i][j][k] = 0;
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j <= i; j++){
            for(int k = 0; k <= 3*(N-1); k++){
                if(w[i] <= k) dp[i+1][j+1][k] = max(dp[i][j+1][k], dp[i][j][k-w[i]] + v[i]);
                else if(j != i) dp[i+1][j+1][k] = dp[i][j+1][k];
            }
        }
    }
    int ans = 0;
    FOR(i, 1, N+1) {
        if(i * (w0) > W) break;
        ans = max(ans, dp[N][i][min(W-(w0*i), 3*(N-1))]);
    }
    cout << ans << endl;
}
