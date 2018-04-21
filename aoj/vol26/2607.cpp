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
int n, d, x;
int p[15][15];
int dp[100005];
/**********************************************/

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n >> d >> x;
    REP(i, d)REP(j, n) cin >> p[i][j];
    

    int cur = x;
    REP(i, d-1){
        REP(j, cur+1) dp[j] = j;
        REP(j, n){
            REP(k, cur+1){
                if(k - p[i][j] >= 0){
                    dp[k] = max(dp[k], dp[k-p[i][j]] + p[i+1][j]);
                }
            }
        }
        int _next = 0;
        REP(k, cur+1) _next = max(_next, dp[k]);
        cur = _next;
    }
    cout << cur << endl;
}
