#include <bits/stdc++.h>

using namespace std;
using LL = long long;
using P = pair<int, int>;
using Tapris = tuple<int, int, int>;

#define REP(i, n) for(LL i = 0; i < n; ++i)
#define FOR(i, a, n) for(LL i = a; i < n; ++i)
#define pb(a) push_back(a)
#define all(x) (x).begin(),(x).end()

const int INF = (int)1e9;
const LL INFL = (LL)1e15;
const int MOD = 1e9 + 7;

int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

//#define int long long

/*************** using variables ***************/
int n;
vector<int> a[2];
int dp1[105], dp2[105];
int ans = 0;
/**********************************************/

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin >> n;
    a[0].resize(n);
    a[1].resize(n);
    REP(i, 2){
        REP(j, n) cin >> a[i][j];
    }
    
    dp1[0] = 0;
    REP(i, n){
        dp1[i+1] = dp1[i] + a[0][i];
    }
    REP(i, n){
        dp2[1] += a[1][i];
    }
    FOR(i, 1, n){
        dp2[i+1] = dp2[i] - a[1][i-1];
    }
    FOR(i, 1, n+1){
        ans = max(dp1[i] + dp2[i], ans);
    }
    cout << ans << endl;

}
