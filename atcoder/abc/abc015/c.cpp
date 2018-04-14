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
#define INFL (LL)1e15
#define MOD 1000000007
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

//#define int long long

/*************** using variables ***************/
int n, k;
int t[6][6];
bool ans = false;
/**********************************************/

void dfs(int num, int depth){
    if(depth == n){
        if(num == 0) ans = true;
        return;
    }
    REP(i, k){
        dfs(num xor t[depth][i], depth+1);
    }
}

signed main(){
    cin >> n >> k;
    REP(i, n){
        REP(j, k){
            cin >> t[i][j];
        }
    }
    
    REP(i, k){
        dfs(t[0][i], 1); 
    }

    if(ans) cout << "Found" << endl;
    else cout << "Nothing" << endl;
}
