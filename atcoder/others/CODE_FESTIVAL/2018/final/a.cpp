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

    int n, m;
    cin >> n >> m;

    vector<int> a(m), b(m), l(m);
    REP(i, m) cin >> a[i] >> b[i] >> l[i];

    vector<vector<int>> num(n);
    REP(i, m){
        num[a[i]-1].pb(l[i]);
        num[b[i]-1].pb(l[i]);
    }
    REP(i, n) sort(all(num[i]));

    int ans = 0;
    REP(i, n){
        REP(j, num[i].size()){
            if(num[i][j] >= 1270) break;
            ans += upper_bound(all(num[i]), 2540 - num[i][j]) - lower_bound(all(num[i]), 2540 - num[i][j]);
        }
        int n1270 = (int)(upper_bound(all(num[i]), 1270) - lower_bound(all(num[i]), 1270));
        ans += n1270 * (n1270 - 1) / 2;
    }
    cout << ans << endl;
}