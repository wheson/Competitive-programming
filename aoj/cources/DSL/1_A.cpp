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

// UnionFind木を構築します
// 使用例:
// UnionFind uni(n);
// cout << uni.Same(1, 2) ? "YES" : "NO" << endl; <- NO
// uni.Unite(1, 2);
// cout << uni.Same(1, 2) ? "YES" : "NO" << endl; <- YES
// cout << uni.GetSize(1) << endl;                <- 2
class UnionFind
{
    private:
      vector<int> par;
      vector<int> rank;
      vector<int> sz;

    public:
      UnionFind(int n) : par(n), rank(n, 0), sz(n, 1)
      {
          iota(par.begin(), par.end(), 0);
      }
      int Find(int x)
      {
          if (par[x] == x) return x;
          else
          {
              int r = Find(par[x]);
              return par[x] = r;
          }
      }
      bool Unite(int x, int y)
      {
          x = Find(x);
          y = Find(y);
          if (x == y) return false;

          if (rank[x] < rank[y]) swap(x, y);
          par[y] = x;
          if (rank[x] == rank[y]) rank[x]++;
          sz[x] += sz[y];
          return true;
      }
      bool Same(int x, int y)
      {
          if (Find(x) == Find(y)) return true;
          else return false;
      }
      int GetSize(int x)
      {
          return sz[Find(x)];
      }
};

signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;
    UnionFind uni(n);
    REP(i, q)
    {
        int c, x, y;
        cin >> c >> x >> y;
        if(c == 0) uni.Unite(x, y);
        else cout << (uni.Same(x, y) ? 1 : 0) << endl;
    }
}