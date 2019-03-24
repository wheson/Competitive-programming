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
    
    int n, k;
    cin >> n >> k;
    vector<int> w(n), p(n);
    REP(i, n) cin >> w[i] >> p[i];
    vector<pair<int, int>> a;
    REP(i, n) a.pb(make_pair(w[i], p[i]));

    double ok = 0, ng = 101;
    REP(i, 10000)
    {
        double mid = (ok + ng) / 2;
        sort(all(a), [&](pair<int, int> a, pair<int, int> b){ return a.first * (a.second - mid) > b.first * (b.second - mid); });
        double ans = a[0].second, sum = a[0].first;
        FOR(j, 1, k)
        {
            ans = (ans * sum + a[j].second * a[j].first) / (sum + a[j].first);
            sum = sum + a[j].first;
        }
        if(ans >= mid) ok = mid;
        else ng = mid;
    }

    printf("%.9f\n", ok);
}