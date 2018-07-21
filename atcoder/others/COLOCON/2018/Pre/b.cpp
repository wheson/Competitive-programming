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
const int MOD = 1e9 + 7;

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, x;
    string s;
    cin >> n >> x >> s;
    vector<int> t(n);
    REP(i, n) cin >> t[i];

    int ans = 0;

    REP(i, n){
        ans += (s[i] == '1' ? min(t[i], x) : t[i]);
    }
    cout << ans << endl;
}
