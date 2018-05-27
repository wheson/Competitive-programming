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
int n, m, a, b;
vector<int> c;
/**********************************************/

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n >> m >> a >> b;
    c.resize(m);
    REP(i,m) cin >> c[i];
    REP(i, m){
        if(n <= a) n += b;
        n -= c[i];
        if(n < 0) {
            cout << i+1 << endl;
            return 0;
        }
    }
    cout << "complete" << endl;
}
