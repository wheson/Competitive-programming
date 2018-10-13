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
const int MOD = 1e9 + 7;

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<int> num;
    for(int i = 1; i*i <= m; i++){
        if(m % i == 0) num.pb(i), num.pb(m / i);
    }
    num.pb(m);
    
    int ans = 1;
    REP(i, num.size()){
        if(num[i] <= m / n){
            ans = max(ans, num[i]);
        }
    }
    
    cout << ans << endl;
}
