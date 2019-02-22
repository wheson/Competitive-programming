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

    int n;
    cin >> n;
    vector<int> a(n);
    REP(i, n) cin >> a[i];

    sort(all(a));

    LL ans1 = 0, ans2 = 0;
    vector<int> keisuu1(n), keisuu2(n);
    REP(i, n) {
        if (i % 2 == 0) keisuu1[i] = 1, keisuu2[i] = -1;
        else keisuu1[i] = -1, keisuu2[i] = 1;

        if (i != 0 && i != n - 1) keisuu1[i] *= 2, keisuu2[i] *= 2;
    }

    sort(all(keisuu1)); sort(all(keisuu2));

    REP(i, n) ans1 += keisuu1[i] * a[i];
    REP(i, n) ans2 += keisuu2[i] * a[i];

    cout << max(ans1, ans2) << endl;
}