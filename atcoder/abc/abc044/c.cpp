#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <tuple>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <cstdio>
#include <numeric>
#define REP(i, n) for(LL i = 0;i < n;i++)
#define REPR(i, n) for(LL i = n;i >= 0;i--)
#define FOR(i, m, n) for(LL i = m;i < n;i++)
#define FORR(i, m, n) for(LL i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define pb(a) push_back(a)
#define all(x) (x).begin(),(x).end()
#define INF (LL)1e15
#define MOD 1000000007
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
typedef pair<LL, LL> LP;
typedef pair<int, P> PP;
typedef pair<LL, LP> LPP;
int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

#define int long long

/*************** using variables ***************/
int n, a;
vector<int> x;
LL dp[55][55][2505];
LL ans = 0;
/**********************************************/

signed main(){
    cin >> n >> a;
    x.resize(n+1);
    REP(i, n) cin >> x[i+1];
    
    dp[0][0][0] = 1;
    REP(i, n+1){
        REP(j, n+1){
            REP(k, a*n+1){
                if(i >= 1 && k < x[i]){
                    dp[i][j][k] = dp[i-1][j][k];
                }else if(i >= 1 && j >= 1 && k >= x[i]){
                    dp[i][j][k] = dp[i-1][j][k] + dp[i-1][j-1][k-x[i]];
                }
                //cout << "i, j, k: " << i << " " << j << " " << k << " " << dp[i][j][k] << endl;
            }
        }
    }

    FOR(i, 1, n+1){
        ans += dp[n][i][i*a];
    }

    cout << ans << endl;
}
