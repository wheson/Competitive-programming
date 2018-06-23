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

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    while(1){
        int n;
        cin >> n;
        if(n == 0) break;
        
        vector<vector<LL>> dp;
        dp.assign(55, vector<LL>(35, 0));

        vector<vector<bool>> sche;
        sche.assign(55, vector<bool>(35, false));

        REP(i, n){
            int x; cin >> x;
            REP(j, x){
                int s; cin >> s;
                sche[i][s] = true;
            }
        }
        REP(i, n) dp[i][0] |= (1LL << i);
        FOR(i, 1, 31){
            REP(j, n){
                dp[j][i] |= dp[j][i-1];
                if(sche[j][i]) REP(k, n){
                    if(sche[k][i]) dp[k][i] |= dp[j][i-1];
                }
            }
        }
        int ans = INF;
        REP(i, 31) REP(j, n) if(dp[j][i] == ((1LL << n) - 1)) ans = min(ans, i);
        if(ans != INF) cout << ans << endl;
        else cout << -1 << endl;
        
    }
}
