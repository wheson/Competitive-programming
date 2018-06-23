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

int n, c;
vector<int> a, b;

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    while(1){
        cin >> n >> c;
        if(n == 0 && c == 0) break;
        a.assign(n, 0);
        b.assign(c, 0);
        REP(i, n) REP(j, 16) {
            int x; cin >> x;
            if(j != 0) a[i] <<= 1;
            a[i] += x;
        }
        REP(i, c) REP(j, 16) {
            int x; cin >> x;
            if(j != 0) b[i] <<= 1;
            b[i] += x;
        }

        vector<vector<int>> dp(35, vector<int>((1<<16), -1));
        dp[0][a[0]] = 0;
        REP(i, n){
            for(int mask = 0; mask < (1 << 16); mask++){
                if(dp[i][mask] != -1){
                    int m = mask | a[i];
                    REP(j, c){
                        int andnum = m & b[j];
                        int notandnum = m & ~b[j];
                        dp[i+1][notandnum] = max(dp[i+1][notandnum], dp[i][mask] + __builtin_popcount(andnum));
                    }
                }
            }
        }

        int ans = 0;
        REP(i, (1 << 16)){
            ans = max(ans, dp[n][i]);
        }
        cout << ans << endl;
    }
}
