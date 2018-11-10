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

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<int> p(m), y(m);
    REP(i, m) cin >> p[i] >> y[i];

    vector<vector<int>> s(n);
    REP(i, m){
        s[p[i]-1].pb(y[i]);
    }
    REP(i, n){
        sort(all(s[i]));
    }

    REP(i, m){
        int num = lower_bound(all(s[p[i]-1]), y[i]) - s[p[i]-1].begin() + 1;
        cout << setfill('0') << setw(12) << p[i] * 1000000 + num << endl;
    }
}