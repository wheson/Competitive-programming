#include <bits/stdc++.h>

using namespace std;
using LL = long long;

#define FOR(i, a, n) for(int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)

const int MOD = 1e9 + 7;

int main()
{
    int n;
    cin >> n;
    vector<int> c(n);
    REP(i, n) cin >> c[i];

    vector<int> color(200005, 0);
    vector<LL> dp(n+1, 0);
    dp[0] = 0, dp[1] = 1;
    color[c[0]] = 1;
    FOR(i, 1, n)
    {
        if(c[i] != c[i-1]) dp[i+1] = (dp[i] + dp[color[c[i]]]) % MOD;
        else dp[i+1] = dp[i];
        
        color[c[i]] = i+1;
    }
    cout << dp[n] << endl;
}