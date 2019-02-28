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

int n, m, k;
vector<vector<int>> tree;
vector<bool> closed;
vector<int> depth;

// 深さを調べる関数
void dfs(int cur){
    for(auto x : tree[cur]){
        if(depth[x] == -1) {
            depth[x] = depth[cur]+1;
            dfs(x);
        }
    }
}

// curが親となる部分木を使えなくする関数
void dfs2(int cur){
    closed[cur] = true;
    for(auto x : tree[cur]){
        dfs2(x);
    }
}

bool check(int cur, int nokori, int k){
    // 一時的に保管
    vector<bool> tmp = closed;
    dfs2(cur);
    vector<int> dlist;

    FOR(i, 1, n+1) if(!closed[i] && i != cur) dlist.push_back(depth[i]);
    
    // もとに戻す
    closed = tmp;
    if(dlist.size() < nokori) return false;

    sort(all(dlist));
    int minsum = 0, maxsum = 0;
    REP(i, nokori) minsum += dlist[i], maxsum += dlist[dlist.size() - i - 1];

    if(minsum <= k && maxsum >= k) return true;
    else return false;
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n >> m >> k;
    
    tree.resize(n+1);
    depth.assign(n+1, -1);
    closed.assign(n+1, false);
    closed[0] = true;

    FOR(i, 1, n+1) {
        int p;
        cin >> p;
        tree[p].push_back(i);
    }
    
    // 深さを調べる
    depth[0] = 0;
    dfs(0);

    // 前から順に置いてもよい最小を見つける
    vector<int> ans(m, -1);
    int turn = 0;
    REP(i, m){
        FOR(j, 1, n+1){
            // jに置いた後，残りm-i-1個がどこかに置けるかどうか
            if(!closed[j] && check(j, m - i - 1, k - depth[j])){
                dfs2(j);
                ans[i] = j;
                k -= depth[j];
                break;
            }
        }
        // i番目がどこにも置けなかった場合は不可能なため-1を出力して終了
        if(ans[i] == -1){
            cout << -1 << endl;
            return 0;
        }
    }

    REP(i, m) cout << ans[i] << " \n"[i == m-1];
}