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
const LL INFL = (LL)1e15;
const int MOD = 1e9 + 7;

int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

class Countings{
    private:
        int mod;
        vector<long long> factList, invList;
        long long Pow(long long x, long long n);
    public:
        Countings(int sz, int mod);
        long long Permutation(int n, int r);
        long long Combination(int n, int r);
        long long HomogeneousProduct(int n, int r);
};

Countings::Countings(int sz, int mod) : mod(mod), factList(sz + 1), invList(sz + 1) {
    factList[0] = 1;
    for(int i = 1; i < factList.size(); i++) {
        factList[i] = factList[i - 1] * i % mod;
    }
    invList[sz] = Pow(factList[sz], mod - 2);
    for(int i = sz - 1; i >= 0; i--) {
        invList[i] = invList[i + 1] * (i + 1) % mod;
    }
}

long long Countings::Pow(long long x, long long n){
    long long ret = 1;
    while(n > 0) {
      if(n & 1) ret = ret * x % mod;
      x = x * x % mod;
      n >>= 1;
    }
    return ret;
}

long long Countings::Permutation(int n, int r){
    if(r < 0 || n < r) return 0;
    return factList[n] * invList[n - r] % mod;
}

long long Countings::Combination(int n, int r){
    if(r < 0 || n < r) return 0;
    return factList[n] * invList[r] % mod * invList[n - r] % mod;
}

long long Countings::HomogeneousProduct(int n, int r){
    if(n < 0 || r < 0) return 0;
    return (r == 0 ? 1 : Combination(n + r - 1, r));
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, p;
    cin >> n >> p;
    vector<int> a(n);
    REP(i, n) cin >> a[i];

    int cnt = 0;
    REP(i, n) if(a[i] % 2 == 0) cnt++;
    
    LL sum = pow(2LL, cnt);
    LL ans = 0;
    Countings countings(n, MOD);
    REP(i, n-cnt+1){
        if(p == 0){
            if(i % 2 == 0) ans += sum * countings.Combination(n-cnt, i);
        }else{
            if(i % 2 == 1) ans += sum * countings.Combination(n-cnt, i);
        }
    }

    cout << ans << endl;
}
