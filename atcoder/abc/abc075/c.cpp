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
#include <numeric>
#define REP(i, n) for(LL i = 0;i < n;i++)
#define REPR(i, n) for(LL i = n;i >= 0;i--)
#define FOR(i, m, n) for(LL i = m;i < n;i++)
#define FORR(i, m, n) for(LL i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define pb(a) push_back(a)
#define all(x) (x).begin(),(x).end()
#define INF (LL)1e15
#define MOD 1000000007
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
typedef pair<LL, LL> LP;
typedef pair<int, P> PP;
typedef pair<LL, LP> LPP;
int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

/*************** using variables ***************/
int n, m;
vector<int>a, b;
bool graph[55][55];
vector<bool> close;
int ans = 0;
/**********************************************/

void dfs(int cur_p){
    close[cur_p] = true;

    REP(i, n){
        if(graph[cur_p][i+1] == false) continue;
        if(close[i+1] == true) continue;
        dfs(i+1);
    }
}

int main(){
    cin >> n >> m;
    a.resize(m+5); b.resize(m+5);
    close.resize(n+5);
    REP(i, m) cin >> a[i] >> b[i];
    
    REP(i, 55){
        REP(j, 55){
            graph[i][j] = false;
            graph[j][i] = false;
        }
    }
    REP(i, m){
        graph[a[i]][b[i]] = true;
        graph[b[i]][a[i]] = true;
    }
    REP(i, m){
        graph[a[i]][b[i]] = false;
        graph[b[i]][a[i]] = false;
        
        REP(j, n) close[j+1] = false;

        dfs(1);    
        bool bridge = false;
        REP(j, n){
            if(close[j+1] == false) bridge = true;
        }
        
        if(bridge) ans++;

        graph[a[i]][b[i]] = true;
        graph[b[i]][a[i]] = true;
    }

    cout << ans << endl;
}
