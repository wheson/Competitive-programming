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
const LL INFL = (LL)1e18;
const int MOD = 1e9 + 7;

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    
    vector<int> dp(n+5, INF);
    dp[0] = -INF;

    REP(i, n){
        int x;
        cin >> x;
        int ok = 0, ng = n+2;
        while(abs(ok - ng) > 1){
            int mid = (ok + ng) / 2;
            if(dp[mid] < x) ok = mid;
            else ng = mid;
        }
        dp[ok+1] = x;
    }
    
    int num = 0;

    REP(i, n) if(dp[i+1] != INF) num++; else break;

    cout << n - num << endl;
}
