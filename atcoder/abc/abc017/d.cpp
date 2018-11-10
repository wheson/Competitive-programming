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

    vector<LL> dp(n+1, 0);
    dp[0] = 1;
    int l = 0;
    LL sum = 1LL;
    map<int, bool> mp;
    REP(i, n){
        while(mp[f[i]]){
            if(l-1 >= 0) sum = (sum + MOD - dp[l-1]) % MOD;
            cout << "f " << f[l] << endl;
            mp[f[l]] = false;
            l++;
        }
        mp[f[l]] = true;
        dp[i+1] = sum;
        sum = (sum + dp[i+1]) % MOD;
    }
    for(auto x : dp) cout << x << endl;
    cout << dp[n] << endl;
}