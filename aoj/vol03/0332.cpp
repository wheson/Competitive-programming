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
vector<int> c;
bool dp[105][105];
/**********************************************/

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin >> n;
    c.resize(n);
    REP(i, n) cin >> c[i];

    REP(i, n-1){
        FOR(j, i+1, n){
            if(c[i] != c[j]) break;
            dp[i][j] = true;
        }
    }
    
    for(int len = 4; len <= n; len++){
        for(int l = 0; l < n; l++){
            int r = l + len - 1;
            if(r >= n) break;
            
            // ok ok パターン
            for(int m = l+2; m < n-1; m++){
                if(dp[l][m-1] && dp[m][r]) dp[l][r] = true;
            }
            // x ok x パターン
            if(c[l] == c[r] && dp[l+1][r-1]){
                for(int m = r; m < n; m++){
                    if(c[l] != c[m]) break;
                    dp[l][m] = true;
                }
                for(int m = l; m >= 0; m--){
                    if(c[r] != c[m]) break;
                    dp[m][r] = true;
                }
            }
            // x ok x ok x パターン
            for(int m = l+1; m < r; m++){
                if(c[l] == c[m] && c[m] == c[r]){
                    if(l + 1 != m && !dp[l+1][m-1]) continue;
                    if(m + 1 != r && !dp[m+1][r-1]) continue;
                    dp[l][r] = true;
                }
            }
        }
    }

    cout << (dp[0][n-1] ? "yes":"no") << endl;
}
