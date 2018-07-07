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

    int n;
    while(cin >> n, n){
        vector<vector<int>> t(n, vector<int>(n+1, 0));
        REP(i, n) REP(j, n+1) cin >> t[i][j];

        vector<int> dp(1 << 16, INF);
        dp[0] = 0;
        for(int mask = 1; mask < (1 << n); mask++){
            REP(i, n) if(mask & (1 << i)){
                int sum = dp[mask ^ (1 << i)];
                int min_num = t[i][0];
                REP(j, n) if(i != j && mask & (1 << j)){
                    min_num = min(min_num, t[i][j+1]);
                }

                dp[mask] = min(dp[mask], sum + min_num);
            }
        }
        
        cout << dp[(1 << n) - 1] << endl;
    }
}
