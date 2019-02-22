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

    int n, m, p, q, r;
    cin >> n >> m >> p >> q >> r;
    vector<int> x(r), y(r), z(r);
    REP(i, r) cin >> x[i] >> y[i] >> z[i];
    vector<vector<int>> happy(n, vector<int>(m, 0));
    REP(i, r){
        happy[x[i]-1][y[i]-1] = z[i];
    }

    int ans = 0;
    for(int mask = 0; mask < (1 << n); mask++){
        if(__builtin_popcount(mask) == p){
            int sum = 0;
            vector<int> man;
            REP(i, m){
                int msum = 0;
                REP(j, n){
                    if(mask & (1 << j)){
                        msum += happy[j][i];
                    }
                }
                man.pb(msum);
            }
            sort(all(man), greater<int>());
            REP(i, q) sum += man[i];
            ans = max(ans, sum);
        }
    }
    cout << ans << endl;
}