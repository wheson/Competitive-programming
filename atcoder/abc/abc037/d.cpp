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
    
    int h, w;
    cin >> h >> w;
    vector<vector<int>> a(h, vector<int>(w));
    REP(i, h) REP(j, w) cin >> a[i][j];

    vector<pair<int, pair<int, int>>> t;
    REP(i, h) REP(j, w) t.push_back(make_pair(a[i][j], make_pair(i, j)));
    sort(all(t), [](auto a, auto b) { return a.first < b.first; });

    vector<vector<int>> keiro(h, vector<int>(w, 0));
    REP(i, h) REP(j, w) keiro[i][j] = 1;
    REP(m, t.size())
    {
        int i = (t[m].second).first, j = (t[m].second).second;
        int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
        REP(k, 4)
        {
            if(i+dy[k] < 0 || i+dy[k] >= h || j+dx[k] < 0 || j+dx[k] >= w) continue;
            if(a[i][j] > a[i+dy[k]][j+dx[k]]) keiro[i][j] = (keiro[i][j] + keiro[i+dy[k]][j+dx[k]]) % MOD;
        }
    }
    LL ans = 0;
    REP(i, h) REP(j, w) ans = (ans + keiro[i][j]) % MOD;

    cout << ans << endl;
}