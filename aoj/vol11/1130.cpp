#include <bits/stdc++.h>

using namespace std;
using LL = long long;
using P = pair<int, int>;
using Tapris = tuple<int, int, int>;

#define REP(i, n) for(LL i = 0; i < n; ++i)
#define FOR(i, a, n) for(LL i = a; i < n; ++i)
#define pb(a) push_back(a)
#define all(x) (x).begin(),(x).end()

const int INF = (int)1e9;
const LL INFL = (LL)1e15;
const int MOD = 1e9 + 7;

int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

//#define int long long

/*************** using variables ***************/
int h, w;
char t[21][21];
/**********************************************/

void dfs(int x, int y){
    if(t[y][x] != '.' && t[y][x] != '@') return;
    t[y][x] = '*';
    if(x+1 < w)  dfs(x+1, y);
    if(x-1 >= 0) dfs(x-1, y);
    if(y+1 < h)  dfs(x, y+1);
    if(y-1 >= 0) dfs(x, y-1);
    return;
}

int solve(){
    int atx = -1, aty = -1;
    REP(i, h){
        if(atx != -1 && aty != -1) break;
        REP(j, w){
            if(t[i][j] == '@'){
                aty = i; atx = j;
                break;
            }
        }
    }
    dfs(atx, aty);
    int ans = 0;
    REP(i, h){
        REP(j, w){
            if(t[i][j] == '*') ans++;
        }
    }
    return ans;
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    while(cin >> w >> h, h + w){
        REP(i, h){
            REP(j, w){
                cin >> t[i][j];
            }
        }
        cout << solve() << endl;
    }
}
