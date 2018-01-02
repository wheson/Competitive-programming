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
#define REP(i, n) for(LL i = 0;i < n;i++)
#define REPR(i, n) for(LL i = n;i >= 0;i--)
#define FOR(i, m, n) for(LL i = m;i < n;i++)
#define FORR(i, m, n) for(LL i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define pb(a) push_back(a)
#define all(x) (x).begin(),(x).end()
#define INF 999999999
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
int a, b;
bool graph[10][10];
bool closed[10];
int ans = 0;
/**********************************************/

bool isAllClosed(){
    REP(i, n){
        if(!closed[i]) return false; 
    }
    return true;
}

void dfs(int now){
    if(isAllClosed()){ 
        ans++;
        return;
    }
    
    /*REP(i, m){
        if(closed[i]) cout << "true ";
        else cout << "false ";
    }
    cout << endl;
    */
    REP(i, n){
        if(!closed[i] && (graph[now][i] || graph[i][now])){
            closed[i] = true;
            dfs(i);
            closed[i] = false;
        }
    }
    return;
}

int main(){
    cin >> n >> m;
    closed[0] = true;
    REP(i, m){
        cin >> a >> b;
        graph[a-1][b-1] = true;
        graph[b-1][a-1] = true;
    }
    
    dfs(0);
    cout << ans << endl;
}
