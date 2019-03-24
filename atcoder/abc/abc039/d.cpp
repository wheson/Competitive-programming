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
const int MOD = 1e9 + 7;

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    REP(i, h) cin >> s[i];

    vector<string> ori = s;

    int dx[] = {1, -1, 0, 1, -1,  1, -1,  0};
    int dy[] = {1,  1, 1, 0,  0, -1, -1, -1};
    REP(i, h) REP(j, w)
    {
        if(ori[i][j] == '.') continue;
        bool flag = true;
        REP(k, 8)
        {
            if (i + dy[k] < 0 || i + dy[k] >= h || j + dx[k] < 0 || j + dx[k] >= w) continue;
            if(ori[i+dy[k]][j+dx[k]] != '#') flag = false;
        }
        if (flag)
        {
            s[i][j] = '*';
            REP(k, 8)
            {
                if (i + dy[k] < 0 || i + dy[k] >= h || j + dx[k] < 0 || j + dx[k] >= w) continue;
                if(s[i + dy[k]][j + dx[k]] == '#') s[i + dy[k]][j + dx[k]] = '.';
            }
        }
    }
    REP(i, h) REP(j, w)
    {
        if(s[i][j] == '#')
        {
            cout << "impossible" << endl;
            return 0;
        }
    }
    cout << "possible" << endl;
    REP(i, h)
    {
        REP(j, w)
        {
            cout << (s[i][j] == '*' ? '#' : '.');
        }
        cout << endl;
    }
}
