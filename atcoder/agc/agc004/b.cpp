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

/*************** using variables **************/
int n, x;
vector<int> a;
int dp[2005];
/**********************************************/

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n >> x;
    a.resize(n);
    REP(i, n) cin >> a[i];
    
    REP(i, n) dp[i] = a[i];
    
    int ans = INFL;
    REP(k, n){
        int cost = 0;
        FOR(i, n, n*2){
            int scost = a[i%n];
            scost = min(dp[i%n], a[(i-k)%n]);
            cost += scost;
            dp[i%n] = scost;
        }
        ans = min(ans, cost + x*k);
    }
    cout << ans << endl;
}
