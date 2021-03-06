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
const LL INFL = (LL)1e19;
const int MOD = 1e9 + 7;

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n, m, c;
    cin >> n >> m >> c;
    vector<int> b(m);
    REP(i, m) cin >> b[i];
    
    int ans = 0;
    REP(i, n){
        vector<int> a(m);
        REP(i, m) cin >> a[i];
        int sum = c;
        REP(i, m) sum += a[i] * b[i];
        if(sum > 0) ans++;
    }
    cout << ans << endl;
}