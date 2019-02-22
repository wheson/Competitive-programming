#include <bits/stdc++.h>
#define int long long

using namespace std;
using LL = long long;

#define FOR(i, a, n) for(int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)

#define pb(a) push_back(a)
#define all(x) (x).begin(),(x).end()

const int INF = (int)1e9;
const LL INFL = (LL)1e19;
const int MOD = (int)1e9 + 7;

int h, w;
vector<string> s;
int cntw, cntb;
int ans = 0;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
void dfs(int x, int y, bool white){
    s[y][x] = ',';
    if(white) cntw++;
    else cntb++;

    REP(i, 4){
        if(x+dx[i] >= 0 && x+dx[i] < w && y+dy[i] >= 0 && y+dy[i] < h &&
           s[y+dy[i]][x+dx[i]] == (white ? '#' : '.')) {
            dfs(x + dx[i], y + dy[i], !white);
        }
    }
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> h >> w;
    s.resize(h);
    REP(i, h) cin >> s[i];

    REP(i, h) REP(j, w) if(s[i][j] != ','){
        cntb = 0; cntw = 0;
        dfs(j, i, s[i][j] == '.');
        ans += cntb * cntw;
    }
    cout << ans << endl;
}