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

int N, C;
int d[35][35], c[505][505];
vector<int> color[3];
int ans = INF;

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> C;
    REP(i, C) REP(j, C) cin >> d[i][j];
    REP(i, N) REP(j, N) cin >> c[i][j], c[i][j]--;
    REP(i, N) REP(j, N) color[(i+j)%3].pb(c[i][j]);

    if(N == 1){
        ans = 0;
    }else{
        int color_sum[30][3];
        REP(i, 30) REP(j, 3) color_sum[i][j] = 0;
        REP(i, C) for(auto x: color[0]) color_sum[i][0] += d[x][i];
        REP(i, C) for(auto x: color[1]) color_sum[i][1] += d[x][i];
        REP(i, C) for(auto x: color[2]) color_sum[i][2] += d[x][i];
        REP(i, C) REP(j, C) REP(k, C){
            if(i == j || i == k || j == k) continue;
            int sum = color_sum[i][0] + color_sum[j][1] + color_sum[k][2];
            ans = min(ans, sum);
        }
    }
    cout << ans << endl;
}
