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
const LL INFL = (LL)1e15;
const int MOD = 1e9 + 7;

int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

/*************** using variables **************/
int a[4][4];
/**********************************************/

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    REP(i, 4) REP(j, 4) cin >> a[i][j];
    bool flag = false;
    REP(i, 4) REP(j, 3) if(a[i][j] == a[i][j+1]) flag = true;
    REP(i, 3) REP(j, 4) if(a[i][j] == a[i+1][j]) flag = true;
    if(flag) cout << "CONTINUE" << endl;
    else cout << "GAMEOVER" << endl;
}
