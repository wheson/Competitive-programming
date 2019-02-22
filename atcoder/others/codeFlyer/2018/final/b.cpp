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

    int n, q;
    cin >> n >> q;
    vector<int> x(n);
    REP(i, n) cin >> x[i];
    vector<LL> ruiseki(n+1);
    REP(i, n) ruiseki[i+1] += ruiseki[i] + x[i];
    vector<LL> c(q), d(q);
    REP(i, q) cin >> c[i] >> d[i];
    REP(i, q){
        int r = (int)(upper_bound(all(x), c[i] + d[i]) - x.begin()) - 1;
        int l = (int)(lower_bound(all(x), c[i] - d[i]) - x.begin());

        LL xx = 0, yy = 0, zz = 0;

        int mid = (int)(lower_bound(all(x), c[i]) - x.begin());
        xx = ruiseki[r+1] - ruiseki[mid] - c[i] * (r - mid + 1);

        mid = (int)(upper_bound(all(x), c[i]) - x.begin()) - 1;
        yy = abs(ruiseki[mid+1] - ruiseki[l] - c[i] * (mid - l + 1));

        zz = d[i] * (n - (r - l + 1));
        cout << xx + yy + zz << endl;
    }
}