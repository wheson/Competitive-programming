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

    int h, m, s, c1, c2;
    cin >> h >> m >> s >> c1 >> c2;

    int st = h * 3600 + m * 60 + s;
    int cur = st;
    int cnt1 = 0, cnt2 = 0;
    int mintime = INF, maxtime = -1;
    while(cur++, cnt1 <= c1 && cnt2 <= c2){
        if((cur - 1) % 60 * 60 < (cur - 1) % 3600 && cur % 60 * 60 >= cur % 3600) cnt1++;

        if((cur - 1) % 3600 * 12 < (cur - 1) % (3600*12) && cur % 3600 * 12 >= cur % (3600*12)) cnt2++;

        if(cur%60*60 == cur%3600 || cur%3600*12 == cur%(3600*12)) continue;

        if(cnt1 == c1 && cnt2 == c2){
            mintime = min(mintime, cur);
            maxtime = max(maxtime, cur);
        }
    }

    if(mintime == INF) cout << -1 << endl;
    else cout << mintime - st << " " << maxtime - st << endl;
}