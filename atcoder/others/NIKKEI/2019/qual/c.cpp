#include <bits/stdc++.h>
#define int long long

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

    int n;
    cin >> n;
    vector<int> a(n), b(n);
    REP(i, n) cin >> a[i] >> b[i];

    vector<pair<int, int>> c;
    REP(i, n){
        c.pb(make_pair(a[i], b[i]));
    }

    sort(all(c), [](pair<int, int> a, pair<int, int> b) {
        int af = a.first, as = a.second, bf = b.first, bs = b.second;
        /*
        if(af + as == bf + bs){
            return min(af, as) > min(bf, bs);
        }else{
            return max(af, as) > max(bf, bs);
        }
        */
        return af + as > bf + bs;
    });
    LL ans = 0;
    REP(i, n){
        if(i % 2 == 0){
            ans += c[i].first;
        }else{
            ans -= c[i].second;
        }
    }
    cout << ans << endl;
}