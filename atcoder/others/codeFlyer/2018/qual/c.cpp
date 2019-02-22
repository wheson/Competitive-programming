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

    int n, d;
    cin >> n >> d;
    vector<LL> x(n);
    REP(i, n) cin >> x[i];

    vector<LL> l(n), r(n);
    int left = 0, right = 0;
    REP(i, n){
        while(right < n && x[right] - x[i] <= d) right++;
        while(left < i && x[i] - x[left] > d) left++;

        r[i] = right - 1;
        l[i] = left;
    }

    LL ans = 0;
    REP(i, n) ans += (r[i] - i) * (i - l[i]);
    REP(i, n) ans -= (r[i] - i) * (r[i] - i - 1) / 2;
    cout << ans << endl;
}
