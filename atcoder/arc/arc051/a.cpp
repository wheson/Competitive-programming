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
int x[3], y[3], r;
/**********************************************/

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> x[0] >> y[0] >> r;
    REP(i, 2) cin >> x[i+1] >> y[i+1];
    
    bool flag1 = false;
    bool flag2 = false;
    for(int i = x[1]; i <= x[2]; i++){
        for(int j = y[1]; j <= y[2]; j++){
            if((x[0] - i)*(x[0] - i) + (y[0] - j)*(y[0] - j) > r*r) flag1 = true;
        }
    }
    if(x[0]+r > x[2] || x[0]-r < x[1] || y[0]+r > y[2] || y[0]-r < y[1]) flag2 = true;
    if(flag2) cout << "YES" << endl;
    else cout << "NO" << endl;
    if(flag1) cout << "YES" << endl;
    else cout << "NO" << endl;
}
