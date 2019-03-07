#include <bits/stdc++.h>
#define int long long

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

class UnionFind {
    private:
        vector<int> parent;  // 親
        vector<int> rank;    // 木の深さ
        vector<int> size;    // 根の持つ大きさ

    public:
        UnionFind(int n);          // n要素で初期化
        int find(int x);           // 木の根を返す
        void unite(int x, int y);  // xとyの属する集合を併合
        bool same(int x, int y);   // xとyが同じ集合に属するか否か
        int getSize(int x);        // xの属する集合の大きさ
};

UnionFind::UnionFind(int n) : parent(n), rank(n, 0), size(n, 1) {
    for (int i = 0; i < n; i++) parent[i] = i;
}

int UnionFind::find(int x) {
    if (parent[x] == x) {
        return x;
    } else {
        int r = find(parent[x]);
        return parent[x] = r;
    }
}

void UnionFind::unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;

    if (rank[x] < rank[y]) {
        parent[x] = y;
    } else {
        parent[y] = x;
        if (rank[x] == rank[y]) rank[x]++;
    }
    size[find(x)] = size[x] + size[y];
}

bool UnionFind::same(int x, int y) { return find(x) == find(y); }

int UnionFind::getSize(int x) { return size[find(x)]; }

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m);
    REP(i, m) cin >> a[i] >> b[i];
    reverse(all(a));
    reverse(all(b));

    UnionFind uf(n+1);
    vector<LL> ans(m);
    ans[0] = n * (n-1) / 2;
    REP(i, m-1){
        if(uf.same(a[i], b[i])){
            ans[i+1] = ans[i];
        }else{
            ans[i+1] = ans[i] - uf.getSize(a[i]) * uf.getSize(b[i]);
            uf.unite(a[i], b[i]);
        }
    }
    reverse(all(ans));
    REP(i, m) cout << ans[i] << endl;
}