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

class BipartiteMatching{
    private:
        int n; // 頂点数
        vector<vector<int>> graph;
        vector<int> match;
        vector<int> used;
        bool Dfs(int v);
    public:
        BipartiteMatching(int n);
        void AddEdge(int u, int v);
        int Run();
        int Match(int u);
};

BipartiteMatching::BipartiteMatching(int n): 
    n(n),
    graph(n),
    match(n),
    used(n)
{}

void BipartiteMatching::AddEdge(int u, int v){
    graph[u].push_back(v);
}

bool BipartiteMatching::Dfs(int v){
    used[v] = true;
    for(int u : graph[v]){
        int w = match[u];
        if(w == -1 || (!used[w] && Dfs(w))){
            match[v] = u;
            match[u] = v;
            return true;
        }
    }
    return false;
}

int BipartiteMatching::Run(){
    int res = 0;
    fill(begin(match), end(match), -1);
    for(int v = 0; v < n; ++v){
        if(match[v] == -1){
            fill(begin(used), end(used), false);
            if(Dfs(v)) res++;
        }
    }
    return res;
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int r, c;
    cin >> r >> c;
    vector<string> s(r);
    REP(i, r) cin >> s[i];

    BipartiteMatching bm(r * c);
    REP(i, r) REP(j, c) {
        if(s[i][j] == '.'){
            if(i > 0 && s[i-1][j] == '.') bm.AddEdge(i*c + j, (i-1)*c + j);
            if(i < r-1 && s[i+1][j] == '.') bm.AddEdge(i*c + j, (i+1)*c + j);
            if(j > 0 && s[i][j-1] == '.') bm.AddEdge(i*c + j, i*c + j-1);
            if(j < c-1 && s[i][j+1] == '.') bm.AddEdge(i*c + j, i*c + j+1);
        }
    }

    int ans = -bm.Run();
    REP(i, r) REP(j, c) if(s[i][j] == '.') ans++;
    cout << ans << endl;
}
