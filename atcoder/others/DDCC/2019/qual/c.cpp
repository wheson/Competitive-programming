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

    LL ans = 0;
    vector<LL> vec(n+1), vec2(n+1);
    vec[0] = 0;
    REP(i, n){
        vec[i+1] = 1LL;
        REP(j, 10){
            (vec[i+1] *= (i+1)) %= MOD;
        }
        vec2[i+1] = vec[i+1];
        vec[i+1] = vec[i+1] + MOD - vec2[i];
        vec[i+1] %= MOD;
    }

    REP(i, n){
        //cout << vec[i+1] << " " << vec2[n/(i+1)] << endl;
        ans = ans + (vec[i+1] * vec2[n/(i+1)]) % MOD;
        ans %= MOD;
    }
    cout << ans << endl;
}