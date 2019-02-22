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

    int n;
    cin >> n;
    vector<int> a(n);
    REP(i, n) cin >> a[i];

    vector<LL> ruiseki(n+1, 0);
    REP(i, n){
        ruiseki[i+1] = ruiseki[i] + a[i];
    }

    REP(i, n){
        LL ans = 0;
        REP(j, n-i){
            ans = max(ans, ruiseki[j+1+i] - ruiseki[j]);
        }
        cout << ans << endl;
    }
}