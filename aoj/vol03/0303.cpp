#include <bits/stdc++.h>

using namespace std;
using LL = long long;
using P = pair<int, int>;
using Tapris = tuple<int, int, int>;

#define REP(i, n) for(LL i = 0; i < n; ++i)
#define FOR(i, a, n) for(LL i = a; i < n; ++i)
#define pb(a) push_back(a)
#define all(x) (x).begin(),(x).end()

const int INF = (int)1e9;
const LL INFL = (LL)1e15;
const int MOD = 1e9 + 7;

int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

//#define int long long

template<typename T>
class SegmentTree{
    private:
        using F = function<T(T, T)>;
        const int INF = (int)1e9;
        int sz;
        int n;
        const F f;
        vector<T> node;
    public:
        SegmentTree(vector<T>, F f);
        void Update(int idx, T val);
        T GetNum(int a, int b, int k=0, int l=0, int r=-1);
};

template<typename T>
SegmentTree<T>::SegmentTree(vector<T> v, F f) :
    f(f)
    {
    sz = v.size();
    n = 1; while(n < sz) n *= 2;
    node.resize(2*n-1, INF);
    for(int i = 0; i < sz; i++) node[i+n-1] = v[i];
    for(int i = n-2; i >= 0; i--) node[i] = f(node[2*i+1], node[2*i+2]);
    }

template<typename T>
void SegmentTree<T>::Update(int idx, T val){
    idx += (n - 1);

    node[idx] = val;
    while(idx > 0){
        idx = (idx - 1) / 2;
        node[idx] = f(node[2*idx+1], node[2*idx+2]);
    }
}

template<typename T>
T SegmentTree<T>::GetNum(int a, int b, int k, int l, int r){
    if(r < 0) r = n;
    if(r <= a || b <= l) return INF;
    if(a <= l && r <= b) return node[k];

    T vl = GetNum(a, b, 2*k+1, l, (l+r)/2);
    T vr = GetNum(a, b, 2*k+2, (l+r)/2, r);
    return f(vl, vr);
}

/*************** using variables ***************/
int n;
vector<int> c, w;
bool dp[1005][1005];
int dp2[1005][1005];
/**********************************************/

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n;
    c.resize(n);
    w.resize(n);
    
    SegmentTree<int> st(w, [](int a, int b){return a + b;});
    // 右方向
    REP(l, n-1){
        LL sum = 0;
        FOR(r, l+1, n){
            if(c[l] < sum + w[r]) break;
            dp[l][r] = true;
            sum += w[r];
        }
    }

    // 左方向
    for(int r = n-1; r > 0; r--){
        LL sum = 0;
        for(int l = r-1; r >= 0; l--){
            if(c[r] < sum + w[l]) break;
            dp[l][r] = true;
            sum += w[l];
        }
    }
    

}
