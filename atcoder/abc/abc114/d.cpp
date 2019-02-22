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
const int MOD = (int)1e9 + 7;

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
    int n;
    cin >> n;

    map<int, int> mp;
    int ans = 0;
    FOR(i, 2, n+1){
        int num = i;
        for(int p = 2; p*p <= i; p++){
            while(num % p == 0){
                num /= p;
                mp[p]++;
            }
        }
        if(num > 1) mp[num]++;
    }
    int over2 = 0, over4 = 0, over74 = 0, over24 = 0, over14 = 0;
    for(auto x : mp){
        //cout << x.first << " " << x.second << endl;
        if(x.second >= 74) over74++;
        if(x.second >= 24) over24++;
        if(x.second >= 14) over14++;
        if(x.second >= 4) over4++;
        if(x.second >= 2) over2++;
    }

    Countings ct(10000, MOD);
    ans = over74 + over24 * (over2 - 1) + over14 * (over4 - 1) + ct.Combination(over4, 2) * (over2 - 2);

    cout << ans << endl;
}