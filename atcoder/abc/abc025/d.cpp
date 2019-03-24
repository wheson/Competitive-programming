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
    
    vector<vector<int>> a(5, vector<int>(5));
    REP(i, 5) REP(j, 5) cin >> a[i][j];

    int occ = 0;
    int used = 0;
    REP(i, 5) REP(j, 5)
    {
        if(a[i][j] != 0) occ += (1 << (i*5+j));
        if(a[i][j] != 0) used += (1 << (a[i][j] - 1));
    }

    LL dp[1 << 25] = {0};
    dp[0] = 1;
    REP(i, 25)
    {
        REP(j, 1 << 25)
        {
            REP(k, 25)
            {
                if(occ & (1 << k)) continue;
                if(j & (1 << k)) continue;
            }
        }
    }

}