#include <bits/stdc++.h>
#define int long long

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

/*************** using variables **************/
int n;
vector<int> a, b;
/**********************************************/
template <typename T>
using Edge = T;
template <typename T>
using Edges = vector<Edge<T>>;
template <typename T>
using AdjList = vector<Edges<T>>;


AdjList<LL> adj;
int memo[100005];
bool memo_closed[100005];

int g(int cur, int pre);

int f(int cur, int pre){
    if(!memo_closed[cur]){
        Edges<int> edges;
        for(auto edge: adj[cur]) if(edge != pre) edges.pb(edge);
        
        int prod = 1;
        for(auto edge: edges){
            prod *= (f(edge, cur) + g(edge, cur)) % MOD;
            prod %= MOD;
        }
        memo[cur] = prod;
        memo_closed[cur] = true;
    }
    return memo[cur];
}

int g(int cur, int pre){
    Edges<int> edges;
    for(auto edge: adj[cur]) if(edge != pre) edges.pb(edge);

    int prod = 1;
    for(auto edge: edges){
        prod *= f(edge, cur) % MOD;
        prod %= MOD;
    }
    return prod;
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin >> n;
    a.resize(n);
    b.resize(n);
    REP(i, n-1){
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
    }
    adj.resize(n);
    REP(i, n-1){
        adj[a[i]].push_back(b[i]);
        adj[b[i]].push_back(a[i]);
    }
    cout << (f(0, -1) + g(0, -1)) % MOD << endl;

}
