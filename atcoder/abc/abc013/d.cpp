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
const LL INFL = (LL)1e18;
const int MOD = (int)1e9 + 7;

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m, d;
    cin >> n >> m >> d;
    vector<int> a(m);
    REP(i, m) cin >> a[i], a[i]--;

    vector<vector<int>> amida(32, vector<int>(n));
    vector<int> init(n);
    REP(i, n) init[i] = i;
    amida[0] = init;

    for(int i = m-1; i >= 0; i--){
        swap(amida[0][a[i]], amida[0][a[i] + 1]);
    }

    REP(i, 31){
        REP(j, n){
            amida[i+1][j] = amida[i][amida[i][j]];
        }
    }

    vector<int> ans = init;
    REP(i, 32){
        if(d & (1 << i)){
            REP(j, n){
                ans[j] = amida[i][ans[j]];
            }
        }
    }

    REP(i, n) cout << ans[i] + 1 << endl;
}