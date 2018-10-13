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

    int n, T;
    cin >> n >> T;
    vector<int> c(n), t(n);
    REP(i, n) cin >> c[i] >> t[i];

    int ans = INF;
    REP(i, n){
        if(t[i] <= T) ans = min(ans, c[i]);
    }
    cout << (ans != INF ? to_string(ans) : "TLE") << endl;
}
