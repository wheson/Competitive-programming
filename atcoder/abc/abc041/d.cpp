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

    int n, m;
    cin >> n >> m;
    vector<int> x(m), y(m);
    REP(i, m){
        cin >> x[i] >> y[i];
        x[i]--, y[i]--;
    }

    vector<LL> dp(1 << n, 0);
    for(int mask = 0; mask < (1 << n); mask++){
        for(int i = 0; i < n; i++) if(mask & (1 << i)){
            int mask2 = mask ^ (1 << i);
            if(mask2 == 0){
                dp[mask] = 1;
                continue;
            }
            
            bool flag = true;
            for(int j = 0; j < m; j++){
                if(x[j] == i && mask2 & (1 << y[j])) flag = false;
            }
            if(flag) dp[mask] += dp[mask2];

        }
    }

    cout << dp[(1 << n) - 1] << endl;
}
