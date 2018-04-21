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
int N, W, H;
vector<int>x, y, w;
int imosw[100005];
int imosh[100005];
/**********************************************/

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> W >> H;
    x.resize(N);
    y.resize(N);
    w.resize(N);
    REP(i, N) cin >> x[i] >> y[i] >> w[i];
    
    REP(i, N){
        imosw[max(x[i]-w[i], 0)]++;
        imosw[min(x[i]+w[i], W)]--;

        imosh[max(y[i]-w[i], 0)]++;
        imosh[min(y[i]+w[i], H)]--;
    }

    bool flag1 = imosw[0] != 0;
    bool flag2 = imosh[0] != 0;
    FOR(i, 1, W){
        imosw[i] += imosw[i-1];
        flag1 &= imosw[i] != 0;
    }
    FOR(i, 1, H){
        imosh[i] += imosh[i-1];
        flag2 &= imosh[i] != 0;
    }
    cout << (flag1 || flag2 ? "Yes":"No") << endl;
}
