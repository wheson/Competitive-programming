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
    
    LL n, k;
    cin >> n >> k;

    double ans = 1.0 * (1.0 * (k-1) * (n-k) * 6 + (k-1) * 3 + (n-k) * 3 + 1) / n / n / n;

    printf("%.11f\n", ans);
}