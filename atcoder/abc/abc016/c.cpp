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
#include <climits>
#define REP(i, n) for(LL i = 0;i < n;i++)
#define REPR(i, n) for(LL i = n;i >= 0;i--)
#define FOR(i, m, n) for(LL i = m;i < n;i++)
#define FORR(i, m, n) for(LL i = m;i >= n;i--)
#define pb(a) push_back(a)
#define all(x) (x).begin(),(x).end()
#define INF (int)1e9
#define INFL (LL)1e11
#define MOD 1000000007
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

//#define int long long

/*************** using variables ***************/
int n, m;
vector<int> a, b;
int dist[11][11];
/**********************************************/

signed main(){
    cin >> n >> m;
    a.resize(m);
    b.resize(m);
    REP(i, m) cin >> a[i] >> b[i];
    REP(i, 11){
        REP(j, 11){
            dist[i][j] = INF;
        }
    }
    REP(i, m){
        dist[a[i]][b[i]] = 1;
        dist[b[i]][a[i]] = 1;
    }
    
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(i == j) dist[i][j] = INF;
                else dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }

    for(int i = 1; i <= n; i++){
        int ans = 0;
        
        for(int j = 1; j <= n; j++){
            if(dist[i][j] == 2) ans++;
        }
        cout << ans << endl;
    }
}
