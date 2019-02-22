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

    LL n, x;
    cin >> n >> x;

    LL a = n-x, b = x;
    if(a < b) swap(a, b);

    if(a == b){
        cout << 3LL * x << endl;
    }else{
        LL ans = a + b;
        while(a % b != 0){
            ans += 2LL * (a / b) * b;
            a = a % b;
            swap(a, b);
        }
        ans += (a / b * 2LL - 1) * b;
        cout << ans << endl;
    }

}