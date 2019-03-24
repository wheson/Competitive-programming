#include <bits/stdc++.h>
//#define int long long

using namespace std;
using LL = long long;
using P = pair<int, int>;

#define FOR(i, a, n) for (int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)

#define pb(a) push_back(a)
#define all(x) (x).begin(), (x).end()

const int INF = (int)1e9;
const LL INFL = (LL)1e19;
const int MOD = 1e9 + 7;

signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, d, x, y;
    cin >> n >> d >> x >> y;

    if (x % d != 0 || y % d != 0)
    {
        cout << 0 << endl;
        return 0;
    }

    x = abs(x) / d; y = abs(y) / d;

    double nCr[1005][1005] = {0};
    REP(i, 1005) 
    {
        if(i == 0) nCr[i][0] = 1;
        else nCr[i][0] = nCr[i-1][0] / 2, nCr[i][i] = nCr[i][0];
        FOR(j, 1, i)
        {
            nCr[i][j] = (nCr[i-1][j-1] + nCr[i-1][j]) / 2;
        }
    }

    double ans = 0.0;
    REP(i, n + 1)
    {
        int j = n - i;
        if(i < x || j < y) continue;
        if((i - x) % 2 != 0 || (j - y) % 2 != 0) continue;
        ans += nCr[n][i] * nCr[i][(i - x)/2] * nCr[j][(j - y)/2];
    }
    printf("%.9f\n", ans);
}