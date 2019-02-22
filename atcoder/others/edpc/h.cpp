#include <bits/stdc++.h>
//#define int long long

using namespace std;
using LL = long long;

#define FOR(i, a, n) for(int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)

#define pb(a) push_back(a)
#define all(x) (x).begin(),(x).end()

const int INF = (int)1e9;
const LL INFL = (LL)1e19;
const int MOD = (int)1e9 + 7;

const int dx[] = {1, 0};
const int dy[] = {0, 1};

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int h, w;
    cin >> h >> w;

    vector<string> a(h);
    REP(i, h) cin >> a[i];

    vector<vector<int>> dis(h, vector<int>(w, INF));
    vector<vector<bool>> used(h, vector<bool>(w, false));

    dis[0][0] = 0; used[0][0] = true;
    queue<pair<int, int>> que;
    que.push(pair<int, int>(0, 0));
    int cur = 1;
    while(!que.empty()){
        vector<pair<int, int>> p;
        while(!que.empty()){
            p.pb(que.front());
            que.pop();
        }
        for(auto x : p){
            REP(k, 2){
                int i = x.first + dx[k], j = x.second + dy[k];

                if(i < h && i >= 0 && j < w && j >= 0 &&
                a[i][j] == '.' && !used[i][j] && dis[i][j] > cur){
                    dis[i][j] = cur;
                    que.push(pair<int, int>(i, j));
                }
            }
        }
        cur++;
    }

    vector<vector<LL>> dp(h, vector<LL>(w, 0));
    dp[0][0] = 1;
    REP(i, h){
        REP(j, w){
            if(i > 0 && dis[i][j] == dis[i-1][j] + 1) (dp[i][j] += dp[i-1][j]) %= MOD;
            if(j > 0 && dis[i][j] == dis[i][j-1] + 1) (dp[i][j] += dp[i][j-1]) %= MOD;
        }
    }
    cout << dp[h-1][w-1] << endl;
}