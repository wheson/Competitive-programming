#include <bits/stdc++.h>
//#define int long long

using namespace std;
using LL = long long;
using P = pair<int, int>;
using Tapris = tuple<int, int, int>;

#define FOR(i, a, n) for(int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)

#define pb(a) push_back(a)
#define all(x) (x).begin(),(x).end()

const int INF = (int)1e9;
const LL INFL = (LL)1e15;
const int MOD = 1e9 + 7;

int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

// 0-indexed
template <typename Monoid>
class LazySegmentTree{
    private:
        using Func = function<Monoid(Monoid, Monoid)>;
        int n; // 最下段の数
        vector<Monoid> segmentTree; // セグ木本体
        vector<Monoid> lazy; // 遅延評価
        const Func f; // 二項演算
        const Monoid identityElement; // モノイドの単位元

    public:
        LazySegmentTree(vector<Monoid> vec, const Func f, const Monoid identityElement);
        void Update(int idx, Monoid val);
        Monoid Query(int a, int b, int k = 0, int l = 0, int r = -1); // 使う時は区間[a, b)のみ指定すれば良い
        Monoid GetNum(int idx); // 元の要素番号から最下層の値を取得
        void Eval(int k, int l, int r);
};

template <typename Monoid>
LazySegmentTree<Monoid>::LazySegmentTree(vector<Monoid> vec, const Func f, const Monoid identityElement) :
    f(f), identityElement(identityElement)
{
    int sz = vec.size();
    n = 1;
    while(n < sz) n *= 2;
    segmentTree.assign(2*n-1, identityElement);
    lazy.assign(2*n-1, 0);
    for(int i = 0; i < sz; i++) segmentTree[i+n-1] = vec[i];
    for(int i = n-2; i >= 0; i--) segmentTree[i] = f(segmentTree[2*i+1], segmentTree[2*i+2]);
}

template <typename Monoid>
void LazySegmentTree<Monoid>::Update(int idx, Monoid val){
    idx += n - 1;
    segmentTree[idx] = val;
    while(idx > 0){
        idx = (idx - 1) / 2;
        segmentTree[idx] = f(segmentTree[2*idx+1], segmentTree[2*idx+2]);
    }
}

template <typename Monoid>
Monoid LazySegmentTree<Monoid>::Query(int a, int b, int k, int l, int r){
    if(r < 0) r = n;

    if(r <= a || b <= l) return identityElement;

    if(a <= l && r <= b) return segmentTree[k];

    int vl = Query(a, b, 2*k+1, l, (l+r)/2);
    int vr = Query(a, b, 2*k+2, (l+r)/2, r);
    return f(vl, vr);
}

template <typename Monoid>
Monoid LazySegmentTree<Monoid>::GetNum(int idx){
    return segmentTree[idx+n-1];
}

template <typename Monoid>
void LazySegmentTree<Monoid>::Eval(int k, int l, int r){
    if(lazy[k] != 0){
        segmentTree[k] += lazy[k];
        if(r - l > 1){
            lazy[2*k+1] += lazy[k] / 2;
            lazy[2*k+2] += lazy[k] / 2;
        }
        lazy[k] = 0;
    }
}

/*************** using variables ***************/
int n, q;
/**********************************************/

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n >> q;
    int _INT_MAX = pow(2, 31) - 1;
    vector<int> a(n, _INT_MAX);
}
