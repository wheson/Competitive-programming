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
const LL INFL = (LL)1e19;
const int MOD = 1e9 + 7;

int dp[100005];

int dfs(vector<vector<int>> &tree, int cur)
{
    if (tree[cur].empty()) 
    {
        dp[cur] = 0;
        return 0;
    }

    vector<int> child;
    for (auto c : tree[cur])
    {
        child.push_back(dfs(tree, c));
    }

    sort(all(child));
    REP(i, child.size()) child[i] += child.size() - i;
    sort(all(child), greater<int>());

    dp[cur] = child[0];
    return child[0];
}

signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n-1);
    REP(i, n-1) cin >> a[i];

    vector<vector<int>> tree(n+1);
    REP(i, n-1){
        tree[a[i]].push_back(i+2);
    }

    cout << dfs(tree, 1) << endl;
    //REP(i, n) cout << dp[i+1] << endl;
}