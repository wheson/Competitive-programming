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

    map<int, int> mp;
    REP(i, n) mp[a[i]]++;
    int ans = 0;
    ans += min(mp[3], mp[1]);
    if(mp[3] > mp[1]) mp[3] -= mp[1], mp[1] = 0;
    else mp[1] -= mp[3], mp[3] = 0;

    ans += mp[2] / 2;
    mp[2] = mp[2] % 2;

    ans += mp[4], mp[4] = 0;

    ans += mp[3];

    if(mp[2] == 1) ans += 1, mp[1] -= 2;

    if(mp[1] > 0) ans += ceil(1.0 * mp[1] / 4);

    cout << ans << endl;
}