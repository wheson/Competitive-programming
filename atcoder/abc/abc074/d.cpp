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
const LL INFL = (LL)1e15;
const int MOD = 1e9 + 7;

int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};


signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n, 0));
    REP(i, n) REP(j, n) cin >> a[i][j];

    vector<vector<int>> adj = a;
    REP(k, n) REP(i, n) REP(j, n) adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);

    bool flag = true;
    REP(i, n) REP(j, n) if(adj[i][j] != a[i][j]) flag = false;

    if(!flag){
        cout << -1 << endl;
        return 0;
    }

    REP(i, n) REP(j, n) REP(k, n){
        if(i != k && j != k && adj[i][j] == adj[i][k] + adj[k][j]) a[i][j] = 0;
    }
    
    LL ans = 0;
    REP(i, n){
        REP(j, n){
            ans += a[i][j];
        }
    }
    cout << ans/2 << endl;
}
