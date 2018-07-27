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

    int n;
    cin >> n;
    vector<LL> t(n), a(n), fixed(n, 0);
    REP(i, n) cin >> t[i];
    REP(i, n) cin >> a[i];
    
    int high = -1;
    REP(i, n){
        if(high < t[i]){ fixed[i] = 1; high = t[i]; }
    }

    high = -1;
    for(int i = n-1; i >= 0; i--){
        if(high < a[i]){
            if(fixed[i] != 0 && a[i] != t[i]){
                cout << 0 << endl;
                return 0;
            }
            fixed[i] = 1;
            high = a[i];
        }else{
            if(fixed[i] != 0 && t[i] > a[i]){
                cout << 0 << endl;
                return 0;
            }
        }
    }

    LL ans = 1;
    REP(i, n){
        if(fixed[i] == 0){
            ans = ans * min(t[i], a[i]) % MOD;
        }
    }
    cout << ans << endl;
}
