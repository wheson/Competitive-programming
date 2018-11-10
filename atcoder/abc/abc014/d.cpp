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

void dfs(vector<vector<int>>& graph, vector<int>& depth, vector<vector<int>>& par, int p, int cur, int d){
    depth[cur] = d;
    par[0][cur] = p;
    for(auto next : graph[cur]){
        if(next != p) dfs(graph, depth, par, cur, next, d+1);
    }
}

void parent(vector<vector<int>>& graph, vector<int>& depth, vector<vector<int>>& par){
    dfs(graph, depth, par, -1, 0, 0);
    int n = graph.size();

    REP(i, 20-1){
        REP(j, n){
            if(par[i][j] == -1){
                par[i+1][j] = -1;
            }else{
                par[i+1][j] = par[i][par[i][j]];
            }
        }
    }
}

int lca(vector<vector<int>>& graph, vector<int>& depth, vector<vector<int>>& par, int a, int b){
    if(depth[a] > depth[b]) swap(a, b);
    REP(i, 20){
        if((depth[b] - depth[a]) >> i & 1){
            b = par[i][b];
        }
    }

    if(a == b) return a;

    for(int i = 20-1; i >= 0; i--){
        if(par[i][a] != par[i][b]){
            a = par[i][a];
            b = par[i][b];
        }
    }
    return par[0][a];
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<vector<int>> graph(n);
    REP(i, n-1){
        int x, y;
        cin >> x >> y;
        x--, y--;
        graph[x].pb(y);
        graph[y].pb(x);
    }

    vector<int> depth(n, 0);
    vector<vector<int>> par(20, vector<int>(n, 0));
    parent(graph, depth, par);

    int q;
    cin >> q;
    REP(i, q){
        int a, b;
        cin >> a >> b;
        a--, b--;
        int c = lca(graph, depth, par, a, b);
        int ans = depth[a] + depth[b] - 2 * depth[c] + 1;
        cout << ans << endl;
    }
}