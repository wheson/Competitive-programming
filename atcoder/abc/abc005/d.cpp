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
    vector<vector<int>> graph(n+1, vector<int>(n+1, 0));
    REP(i, n) REP(j, n) cin >> graph[i+1][j+1];

    REP(i, n+1) REP(j, n+1){
        if(i > 0) graph[i][j] += graph[i-1][j];
        if(j > 0) graph[i][j] += graph[i][j-1];
        if(i > 0 && j > 0) graph[i][j] -= graph[i-1][j-1];
    }

    vector<int> ans(n*n+1, 0);
    FOR(i, 1, n*n+1){
        ans[i] = ans[i-1];
        vector<int> divisor;
        for(int j = 1; j <= sqrt(i); j++){
            if(i % j == 0){
                divisor.pb(j);
                divisor.pb(i/j);
            }
        }
        for(auto x : divisor){
            int y = i / x;
            REP(k, n-x+1){
                REP(l, n-y+1){
                    ans[i] = max(ans[i], graph[k+x][l+y] - graph[k][l+y] + graph[k][l] - graph[k+x][l]);
                }
            }
        }
    }

    int q;
    cin >> q;
    REP(i, q){
        int p;
        cin >> p;
        cout << ans[p] << endl;
    }
}
