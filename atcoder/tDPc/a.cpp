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
#define REP(i, n) for(LL i = 0;i < n;i++)
#define REPR(i, n) for(LL i = n;i >= 0;i--)
#define FOR(i, m, n) for(LL i = m;i < n;i++)
#define FORR(i, m, n) for(LL i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define pb(a) push_back(a)
#define all(x) (x).begin(),(x).end()
#define INF 999999999
#define MOD 1000000007
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
typedef pair<LL, LL> LP;
typedef pair<int, P> PP;
typedef pair<LL, LP> LPP;
int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

/*************** using variables ***************/
int n;
int p[105];
bool dp[105][100005];
int ans = 0;
/**********************************************/

int main(){
    cin >> n;
    REP(i, n){
        cin >> p[i];
    }
    
    dp[0][0] = true;

    FOR(i, 1, n+1){
        REP(j, 10000){
            if(j >= p[i-1]) dp[i][j] = dp[i-1][j] || dp[i-1][j-p[i-1]];
            else dp[i][j] = dp[i-1][j];

            //if(dp[i][j]) cout << "i: " << i << " j: " << j << endl;
        }
    }

    REP(j, 10000){
        ans += dp[n][j];
    }

    cout << ans << endl;

}
