#include <bits/stdc++.h>
//#define int long long

using namespace std;
using LL = long long;
using P = pair<LL, LL>;

#define FOR(i, a, n) for(int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)

#define pb(a) push_back(a)
#define all(x) (x).begin(),(x).end()

const LL INF = (LL)1e9;
const LL INFL = (LL)1e15;
const LL MOD = 1e9 + 7;

LL dy[]={0, 0, 1, -1, 0};
LL dx[]={1, -1, 0, 0, 0};

/*************** using variables **************/
LL N, K;
vector<LL> x, y, xx, yy;
/**********************************************/

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> K;
    x.resize(N);
    xx.resize(N);
    y.resize(N);
    yy.resize(N);
    REP(i, N){
        cin >> x[i] >> y[i];
        xx[i] = x[i]; yy[i] = y[i];
    }

    sort(all(xx));
    sort(all(yy));

    LL ans = (xx[N-1] - xx[0]) * (yy[N-1] - yy[0]);

    REP(i, N){
        FOR(j, i+1, N){
            REP(k, N){
                FOR(l, k+1, N){
                    LL min_x = xx[i],
                       max_x = xx[j],
                       min_y = yy[k],
                       max_y = yy[l];

                    LL cnt = 0;
                    REP(m, N){
                        if(x[m] >= min_x && x[m] <= max_x && y[m] >= min_y && y[m] <= max_y) cnt++;
                    }
                    if(cnt >= K){
                        ans = min(ans, 1LL * (max_x - min_x) * (max_y - min_y));
                    }
                }
            }
        }
    }
    cout << ans << endl;
}
