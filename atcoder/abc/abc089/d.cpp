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

/*************** using variables ***************/
int h, w, d;
int a[305][305];
int px[300*300+5], py[300*300+5];
int power[300*300+5];
int q;
vector<int> l, r;
/**********************************************/

signed main(){
    cin >> h >> w >> d;
    REP(i, h){
        REP(j, w){
            cin >> a[i][j];
            px[a[i][j]] = j; py[a[i][j]] = i;
        }
    }

    cin >> q;
    l.resize(q);
    r.resize(q);
    REP(i, q) cin >> l[i] >> r[i];
    
    for(int i = 1; i <= d; i++) power[i] = 0;
    for(int i = d+1; i <= h*w; i++){
        power[i] = power[i-d] + abs(px[i] - px[i-d]) + abs(py[i] - py[i-d]);
    }

    REP(i, q){
        cout << power[r[i]] - power[l[i]] << endl;
    }
}
