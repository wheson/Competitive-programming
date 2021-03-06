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

    int p; cin >> p;

    LL ans = 1789997546303;
    REP(i, 1000 - p){
        if(ans % 2 == 0){
            ans = ans / 2;
        }else{
            ans = ans * 3 + 1;
        }
    }
    cout << ans << endl;
}