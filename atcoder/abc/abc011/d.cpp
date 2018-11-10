#include <bits/stdc++.h>
#define int long long

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

vector<int> makeFactList(int n){
    vector<int> ret(n+1, 0);
    ret[0] = 1;
    for(int i = 1; i < ret.size(); i++) {
        ret[i] = ret[i - 1] * i;
    }
    return ret;
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, d, x, y;
    cin >> n >> d >> x >> y;
    x = abs(x), y = abs(y);
    double ans = 0;
    if(x % d != 0 || y % d != 0 || (n - x / d + y / d) & 1){
        printf("%.9Lf\n", ans);
        return 0;
    }
    int xnum = x / d, ynum = y / d;
    int nokori = n - xnum - ynum;

    vector<int> fact = makeFactList(n);
    double hanzen = pow(2LL, 1000);

    for(int i = 0; i <= nokori; i += 2){
        ans += 1.0 * fact[n] / fact[xnum + i/2]  / fact[ynum + (nokori - i)/2] / hanzen / fact[i/2] / fact[(nokori - i) / 2] / hanzen;
    }

    printf("%.9Lf\n", ans);

}