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
int dp[10000005];
/**********************************************/

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n;
    dp[0] = 0;
    
    int cnt = 0;
    int sum = 0;
    REP(i, n+1){
        if(i > sum){
            cnt++;
            sum += cnt;
        }
        dp[i] = cnt;
    }

    sum = 0;
    for(int i = dp[n]; i > 0; i--){
        if(sum + i <= n) {
            sum += i;
            cout << i << endl;
        }
    }
}
