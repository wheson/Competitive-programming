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

    LL h, w, k;
    cin >> h >> w >> k;
    vector<LL> r(k), c(k);
    REP(i, k) cin >> r[i] >> c[i];

    vector<LL> wcnt(w, h), hcnt(h, w);
    REP(i, k) hcnt[r[i]-1]--, wcnt[c[i]-1]--;
    vector<LL> ruisekih(h+1), ruisekiw(w+1);
    REP(i, h) ruisekih[i+1] += ruisekih[i] + hcnt[i];
    REP(i, w) ruisekiw[i+1] += ruisekiw[i] + wcnt[i];

    LL ans = 0;
    int indexh = upper_bound(all(ruisekih), (h*w-k)/2) - ruisekih.begin() - 1;
    REP(i, h){
        ans += abs(i - indexh) * hcnt[i];
    }

    int indexw = upper_bound(all(ruisekiw), (h*w-k)/2) - ruisekiw.begin() - 1;
    REP(i, w){
        ans += abs(i - indexw) * wcnt[i];
    }

    cout << ans << endl;
}