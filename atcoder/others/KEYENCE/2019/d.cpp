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

    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    REP(i, n) cin >> a[i];
    REP(i, m) cin >> b[i];

    vector<bool> closedn(n), closedm(m), closed(n*m+1);

    vector<LL> dp(n*m+1);
    dp[0] = 1;
    REP(i, n*m){
        if(n*m-i)
    }
}