#include <bits/stdc++.h>
//#define int long long

using namespace std;
using LL = long long;

#define FOR(i, a, n) for(int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)

#define pb(a) push_back(a)
#define all(x) (x).begin(),(x).end()

const int INF = (int)1e9;
const LL INFL = (LL)1e19;
const int MOD = (int)1e9 + 7;

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int a, b, q;
    cin >> a >> b >> q;
    vector<LL> s(a), t(b), x(q);
    REP(i, a) cin >> s[i];
    REP(i, b) cin >> t[i];
    REP(i, q) cin >> x[i];

    REP(i, q){
        int sindex1 = lower_bound(all(s), x[i]) - s.begin();
        int sindex2 = sindex1 - 1;
        int tindex1 = lower_bound(all(t), x[i]) - t.begin();
        int tindex2 = tindex1 - 1;

        LL ans = INFL;
        if(sindex1 < s.size() && tindex1 < t.size()){
            ans = min(ans, max(s[sindex1], t[tindex1]) - x[i]);
        }
        if(sindex2 >= 0 && tindex2 >= 0){
            ans = min(ans, x[i] - min(s[sindex2], t[tindex2]));
        }
        if(sindex1 < s.size() && tindex2 >= 0){
            LL dis1 = abs(x[i] - s[sindex1]);
            LL dis2 = abs(x[i] - t[tindex2]);
            ans = min(ans, max(dis1, dis2) + min(dis1, dis2) * 2);
        }
        if(sindex2 >= 0 && tindex1 < t.size()){
            LL dis1 = abs(x[i] - s[sindex2]);
            LL dis2 = abs(x[i] - t[tindex1]);
            ans = min(ans, max(dis1, dis2) + min(dis1, dis2) * 2);
        }

        cout << ans << endl;
    }
}