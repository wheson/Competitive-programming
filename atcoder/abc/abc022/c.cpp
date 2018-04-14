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
#define INF (LL)1e9
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
struct Edge{
    int to, cost;
    Edge(int t, int c){
        to = t; cost = c;
    }
};

/*************** using variables ***************/
int n, m;
LL ans = INF;
LL list[305][305];
LL cost[305][305];
vector<int> first_node;
/**********************************************/



signed main(){
    cin >> n >> m;
    
    REP(i, n+1){
        REP(j, n+1){
            if(i != j){
                list[i][j] = INF;
            }
        }
    }

    REP(i, m){
        int u, v, l;
        cin >> u >> v >> l;
        list[u][v] = l;
        list[v][u] = l;
        if(u == 1 || v == 1) first_node.pb(max(u, v));
    } 
    
    FOR(i, 2, n+1){
        FOR(j, 2, n+1){
            FOR(k, 2, n+1){
                list[j][k] = min(list[j][k], list[j][i] + list[i][k]);
            }
        }
    }
    
    if(first_node.size() <= 1){
        cout << -1 << endl;
        return 0;
    }
    
    for(auto i: first_node){
        for(auto j: first_node){
            if(i != j && list[i][j] != INF){
                ans = min(ans, list[i][j] + list[1][i] + list[1][j]);
            }
        }
    }

    if(ans == INF) ans = -1;
    cout << ans << endl;
}
