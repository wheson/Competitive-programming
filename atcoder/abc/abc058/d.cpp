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
const LL INFL = (LL)1e15;
const int MOD = 1e9 + 7;

int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};


signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    LL n, m;
    cin >> n >> m;
    vector<LL> x(n), y(m);
    REP(i, n) cin >> x[i];
    REP(i, m) cin >> y[i];
    
    LL xsum = 0, ysum = 0;
    REP(i, n) xsum += ((i * x[i]) - ((n-i-1) * x[i])), xsum %= MOD;
    REP(i, m) ysum += ((i * y[i]) - ((m-i-1) * y[i])), ysum %= MOD;
    cout << xsum * ysum % MOD << endl;
}
