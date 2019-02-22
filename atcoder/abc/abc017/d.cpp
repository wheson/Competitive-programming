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

    int n, m;
    cin >> n >> m;
    vector<int> f(n);
    REP(i, n) cin >> f[i];

    vector<LL> dp(n+1, 0), h(n, 0), g(n, 0), ruiseki(n+2, 0);
    map<int, int> mp;
    REP(i, n){
        g[i] = mp[f[i]];
        h[i] = max((i == 0 ? 0 : h[i-1]), g[i]);
        mp[f[i]] = i+1;
    }

    dp[0] = 1;
    ruiseki[1] = dp[0];
    REP(i, n){
        dp[i+1] = (MOD + ruiseki[i+1] - ruiseki[h[i]]) % MOD;
        (ruiseki[i+2] = dp[i+1] + ruiseki[i+1]) %= MOD;
    }

    //for(auto x : h) cout << x << endl;
    //for(auto x : dp) cout << x << endl;
    cout << dp[n] << endl;
}