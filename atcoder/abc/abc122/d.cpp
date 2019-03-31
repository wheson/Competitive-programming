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
const LL INFL = (LL)1e19;
const int MOD = 1e9 + 7;

signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    LL dp[105][1 << (3*2)] = {0};

    string s = "ACGT";
    
    REP(i, 1 << (3*2)) dp[3][i] = 1;
    dp[3][0*16+2*4+1*1] = 0;
    dp[3][0*16+1*4+2*1] = 0;
    dp[3][2*16+0*4+1*1] = 0;

    FOR(i, 3, n)
    {
        REP(j, 1 << (3*2))
        {
            int a = j/4/4%4, b = j/4%4, c = j%4;
            // TAGC
            REP(k, 4)
            {
                if(s[b] == 'A' && s[c] == 'G' && s[k] == 'C') continue;
                if(s[b] == 'G' && s[c] == 'A' && s[k] == 'C') continue;
                if(s[b] == 'A' && s[c] == 'C' && s[k] == 'G') continue;
                if(s[a] == 'A' && s[c] == 'G' && s[k] == 'C') continue;
                if(s[a] == 'A' && s[b] == 'G' && s[k] == 'C') continue;

                (dp[i+1][b*16+c*4+k] += dp[i][j]) %= MOD;
            }
        }
    }
    LL ans = 0;
    REP(i, 1 << (3*2))
    {
        (ans += dp[n][i]) %= MOD;
        int a = i/4/4%4, b = i/4%4, c = i%4;
        //cout << s[a] << " " << s[b] << " " << s[c] << " : " << dp[n][i] << endl;
    }
    cout << ans << endl;

}