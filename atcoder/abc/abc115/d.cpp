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
const LL INFL = (LL)1e18;
const int MOD = (int)1e9 + 7;

vector<LL> dp, dp2;
LL dfs(int f, LL num){
    if(num <= 0) return 0;
    if(num >= dp[f]) return dp2[f];

    // B dp[f-1] P dp[f-1] B
    return dfs(f - 1, min(num, dp[f] / 2 + 1) - 1) + (num > dp[f]/2 ? 1 : 0) + dfs(f - 1, num - (dp[f] / 2) - 1);
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    LL n, k;
    cin >> n >> k;

    // dp[i] := i層目の全体の長さ, dp2[i] := i層目のPの数
    dp.assign(n+1, 0), dp2.assign(n+1, 0);
    dp[0] = 1;
    dp2[0] = 1;

    REP(i, n){
        dp[i+1] = dp[i] * 2 + 3;
        dp2[i+1] = dp2[i] * 2 + 1;
    }

    cout << dfs(n, k) << endl;
}