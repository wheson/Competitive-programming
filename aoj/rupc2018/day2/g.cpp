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
#include <bitset>
#include <limits.h>
#define REP(i, n) for(LL i = 0;i < n;i++)
#define REPR(i, n) for(LL i = n;i >= 0;i--)
#define FOR(i, m, n) for(LL i = m;i < n;i++)
#define FORR(i, m, n) for(LL i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define pb(a) push_back(a)
#define all(x) (x).begin(),(x).end()
#define INF (int)1e9
#define MOD 1000000007
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
typedef pair<LL, LL> LP;
typedef pair<int, P> PP;
typedef pair<LL, LP> LPP;
int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

//#define int long long

/*************** using variables ***************/
vector<bool> close;
int ans = 0;
/**********************************************/
struct max_flow {
    struct edge { int to, cap, rev; }; // {行き先, 容量, 逆辺}
int V;
vector<vector<edge>> G;
vector<int> itr, level;

max_flow(int V) : V(V) { G.assign(V,vector<edge>()); }

void add_edge(int from, int to, int cap) {
    G[from].push_back((edge) {to, cap, (int) G[to].size()});
    G[to].push_back((edge) {from, 0, (int) G[from].size()-1});
}

void bfs(int s) {
    level.assign(V,-1);
    queue<int> q;
    level[s] = 0; q.push(s);
    while (!q.empty()) {
        int v = q.front(); q.pop();
        for(auto &e: G[v]){
            if (e.cap > 0 and level[e.to] < 0) {
                level[e.to] = level[v] + 1;
                q.push(e.to);
            }
        }
    }
}

int dfs(int v, int t, int f) {
    if (v == t) return f;
    for (int &i = itr[v]; i < (int) G[v].size(); ++i) {
        edge &e = G[v][i];
        if (e.cap > 0 and level[v] < level[e.to]) {
            int d = dfs(e.to, t, min(f, e.cap));
            if (d > 0) {
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

int run(int s, int t) {
    int ret = 0, f;
    while (bfs(s), level[t] >= 0) {
        itr.assign(V,0);
        while ((f = dfs(s, t, INF)) > 0) ret += f;
    }
    return ret;
}
};
signed main(){
    int n, A, B;
    cin >> n >> A >> B;
    vector<P> vec;
    REP(i, n){
        int a, b;
        cin >> a >> b;
        if(a - b <= A || (a - b >= B && a - b <= 2*A)) ans++;
        else vec.pb(P(a, b));
    }

    max_flow mf(vec.size()*2+2);
    REP(i, vec.size()){
        mf.add_edge(0, i, 1);
        mf.add_edge(vec.size()+i, vec.size()*2+1, 1);
    }

    REP(i, vec.size()){
        REP(j, vec.size()){
            if(i == j) continue;
            int a1 = vec[i].first;
            int a2 = vec[j].first;
            int b1 = vec[i].second;
            int b2 = vec[j].second;
            if((a1+a2)- (b1+b2) <= A || ((a1+a2) - (b1+b2) >= B && (a1+a2) - (b1+b2) <= 2*A)){
                mf.add_edge(i, vec.size()+j, 1);
            }
        }
    }
    cout << ans+mf.run(0, vec.size()*2+1)/2 << endl;
}
