#include <bits/stdc++.h>
#define int long long

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

    int k;
    cin >> k;
    vector<LL> a(k);
    REP(i, k) cin >> a[i];

    LL ans1 = 2, ans2 = 2;
    for(int i = k-1; i >= 0 ; i--){
        if(ans1 % a[i] != 0 && ans1 + a[i] - (ans1 % a[i]) > ans2){
            cout << -1 << endl;
            return 0;
        }
        ans1 = ceil(1.0 * ans1 / a[i]) * a[i];
        ans2 = floor(1.0 * ans2 / a[i]) * a[i] + a[i] - 1;
    }
    
    cout << ans1 << " " << ans2 << endl;
}
