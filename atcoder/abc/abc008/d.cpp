#include <bits/stdc++.h>
//#define int long long

using namespace std;
using LL = long long;
using P = pair<int, int>;

#define FOR(i, a, n) for(int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)

#define pb(a) push_back(a)
#define all(x) (x).begin(),(x).end()

const int INF = (int) 1e9;
const LL INFL = (LL) 1e18;
const int MOD = (int) 1e9 + 7;

int n;
vector<int> x, y;

int dfs(map<tuple<int, int, int, int>, int> &dp, int lx, int ly, int rx, int ry) {
    if (dp.count(tie(lx, ly, rx, ry))) return dp[tie(lx, ly, rx, ry)];

    int sum = 0;
    REP(i, n) {
        if (lx <= x[i] && x[i] < rx && ly <= y[i] && y[i] < ry) {
            int lu = dfs(dp, lx, ly, x[i], y[i]);
            int ld = dfs(dp, lx, y[i] + 1, x[i], ry);
            int ru = dfs(dp, x[i] + 1, ly, rx, y[i]);
            int rd = dfs(dp, x[i] + 1, y[i] + 1, rx, ry);
            sum = max(sum, lu + ld + ru + rd + (rx - lx) + (ry - ly) - 1);
        }
    }
    return dp[tie(lx, ly, rx, ry)] = sum;
}

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int w, h;
    cin >> w >> h >> n;

    map<tuple<int, int, int, int>, int> dp;

    x.resize(n), y.resize(n);
    REP(i, n) {
        cin >> x[i] >> y[i];
        x[i]--, y[i]--;
    }

    cout << dfs(dp, 0, 0, w, h) << endl;
}
