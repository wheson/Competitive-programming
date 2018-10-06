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

    int n, m;
    cin >> n >> m;

    vector<vector<bool>> friends(n, vector<bool>(n, false));

    REP(i, m){
        int a, b;
        cin >> a >> b;
        a--, b--;
        friends[a][b] = true;
        friends[b][a] = true;
    }
    
    int ans = 0;
    for(int mask = 1; mask < (1 << n); mask++){
        bool flag = true;
        for(int i = 0; i < n; i++) if(mask & (1 << i)){
            for(int j = 0; j < n; j++) if(i != j && mask & (1 << j)){
                if(!friends[i][j]){
                    flag = false;
                }
            }
        }
        if(flag){
            ans = max(ans, __builtin_popcount(mask));
        }
    }
    cout << ans << endl;
}
