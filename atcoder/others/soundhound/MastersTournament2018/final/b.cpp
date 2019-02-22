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

    int n, k;
    cin >> n >> k;
    vector<int> b(n);
    REP(i, n) cin >> b[i];

    vector<LL> dp(n+1), dp2(n+1);
    REP(i, n){
        if(i - k + 1 >= 0){
            dp[i+1] = max(dp[i] + b[i], dp2[i - k + 1]);
        }else{
            dp[i+1] += dp[i] + b[i];
        }
        dp2[i+1] = max(dp2[i], dp[i+1]);
    }

    cout << dp[n] << endl;
}