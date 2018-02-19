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
#define INF 1e9
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
int h, w;
string s[55];
int dot_num = 0;
int dis[55][55];
/**********************************************/

void bfs(int x, int y, int num){
    if(y+1 < h && dis[y+1][x] > num && s[y+1][x] == '.'){
        dis[y+1][x] = num;
        bfs(x, y+1, num+1);
    }
    if(y-1 >= 0 && dis[y-1][x] > num && s[y-1][x] == '.'){
        dis[y-1][x] = num;
        bfs(x, y-1, num+1);
    }
    if(x+1 < w && dis[y][x+1] > num && s[y][x+1] == '.'){
        dis[y][x+1] = num;
        bfs(x+1, y, num+1);
    }
    if(x-1 >= 0 && dis[y][x-1] > num && s[y][x-1] == '.'){
        dis[y][x-1] = num;
        bfs(x-1, y, num+1);
    }
    return;
}

signed main(){
    cin >> h >> w;
    REP(i, h) cin >> s[i];
    REP(i, h){
        REP(j, w){
            if(s[i][j] == '.') dot_num++;
        }
    }
    REP(i, 55){
        REP(j, 55){
            dis[i][j] = INF;
        }
    }
    dis[0][0] = 1;
    bfs(0, 0, 2);
    if(dis[h-1][w-1] != INF) cout << dot_num -  dis[h-1][w-1] << endl;
    else cout << -1 << endl;
}
