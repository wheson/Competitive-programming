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

vector<int> num(1005, 0);
vector<int> child[1005];
int ans = 0;

int dfs(int cur){
    if(num[cur] > 0) return num[cur];
    int min_num = INF;
    for(auto x : child[cur]){
        min_num = min(min_num, dfs(x));
    }
    num[cur] = min_num;
    return min_num;
}

void dfs2(int cur){
    for(auto x : child[cur]){
        dfs2(x);
        ans += num[x] - num[cur];
    }
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;


    REP(i, n-1){
        int p;
        cin >> p;
        child[p].pb(i+1);
    }
    REP(i, m){
        int b, c;
        cin >> b >> c;
        num[b] = c;
    }
    
    dfs(0);
    num[0] = 0;
    dfs2(0);

    cout << ans << endl;
}
