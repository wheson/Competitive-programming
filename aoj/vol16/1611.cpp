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
/**********************************************/

int solve(int n, vector<int> w){
    bool dp[305][305];
    LL dp2[305];
    
    REP(i, 305){
        dp2[i] = 0;
        REP(j, 305){
            dp[i][j] = false;
        }
    }

    for(int i = 1; i < n; i++){
        if(abs(w[i-1]-w[i]) <= 1) dp[i-1][i] = true;
    }

    for(int len = 4; len <= n; len += 2){
        REP(l, n){
            int r = l + len - 1;
            if(r >= n) break;

            for(int c = l+2; c < r; c += 2){
                if(dp[l][c-1] && dp[c][r]) dp[l][r] = true;
            }
            
            if(abs(w[l]-w[r]) <= 1 && dp[l+1][r-1]){
                dp[l][r] = true;
            }
        }
    }

    FOR(r, 1, n){
        dp2[r] = dp2[r-1];
        REP(l, r){
            if(dp[l][r]){
                if(l == 0) dp2[r] = max(dp2[r], r - l + 1);
                else dp2[r] = max(dp2[r], dp2[l-1] + (r - l + 1));
            }
        }
    }
    return dp2[n-1];
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n;
    while(cin >> n, n){
        vector<int> w(n, 0);   
        REP(i, n) cin >> w[i];
        cout << solve(n, w) << endl;
    }
   
}
