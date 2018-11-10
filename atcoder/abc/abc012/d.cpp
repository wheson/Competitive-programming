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
const int MOD = (int)1e9 + 7;

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n, vector<int>(n, INF));
    REP(i, n) graph[i][i] = 0;
    REP(i, m){
        int a, b, t;
        cin >> a >> b >> t;
        a--, b--;
        graph[a][b] = t;
        graph[b][a] = t;
    }

    REP(k, n) REP(i, n) REP(j, n){
        graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
    }

    int ans = INF;
    REP(i, n){
        int num = 0;
        REP(j, n){
            num = max(num, graph[i][j]);
        }
        ans = min(ans, num);
    }
    cout << ans << endl;
}