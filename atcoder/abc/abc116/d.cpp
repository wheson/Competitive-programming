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

    int n, k;
    cin >> n >> k;
    vector<int> t(n), d(n);
    REP(i, n) cin >> t[i] >> d[i];
    vector<pair<int, int>> p;
    REP(i, n) p.pb(make_pair(d[i], t[i]));
    sort(all(p), [](pair<int, int> a, pair<int, int> b){ return a.first > b.first; });

    vector<LL> sushi1, sushi2(1, 0);
    map<int, bool> close;
    REP(i, n){
        if(close[p[i].second]){
            sushi2.pb(p[i].first);
        }else{
            sushi1.pb(p[i].first);
            close[p[i].second] = true;
        }
    }
    REP(i, sushi1.size() - 1){
        sushi1[i+1] += sushi1[i];
    }
    REP(i, sushi2.size() - 1){
        sushi2[i+1] += sushi2[i];
    }

    LL ans = 0;
    REP(i, min(k, (int)sushi1.size())){
        if(sushi2.size() > k - i - 1){
            ans = max(ans, 1LL * (i+1) * (i+1) + sushi1[i] + sushi2[k - i - 1]);
            //cout << i+1 << " " << 1LL * (i+1) * (i+1) + sushi1[i] + sushi2[k - i - 1] << " " << sushi1[i] << " " << sushi2[k - i - 1] << endl;
        }
    }
    cout << ans << endl;

}