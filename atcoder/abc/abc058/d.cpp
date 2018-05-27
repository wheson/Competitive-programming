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
const LL INFL = (LL)1e15;
const int MOD = 1e9 + 7;

int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

/*************** using variables **************/
int h, w, a, b;
LL table[200000];
/**********************************************/

LL change_div_mul_mod(LL divisor, LL mod_minus_2, LL mod){
    if(mod_minus_2 == 0) return 1;
    else if(mod_minus_2 % 2 == 0){
        LL d = change_div_mul_mod(divisor, mod_minus_2/2, mod);
        return (d * d) % mod;
    }else{
        return (divisor * change_div_mul_mod(divisor, mod_minus_2-1, mod)) % mod;
    }
}

LL nCr(LL n, LL r){
    return table[n] * change_div_mul_mod(table[r] ,MOD-2, MOD) % MOD * change_div_mul_mod(table[n-r], MOD-2, MOD) % MOD;
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    table[0] = 1;
    for(int i = 1; i < 200000; i++) table[i] = table[i-1] * i % MOD;

    cin >> h >> w >> a >> b;
    LL ans = 0;
    for(int i = b; i < w; i++){
        ans += nCr((h-a-1) + i, i) * nCr((a-1) + (w-i-1), a-1);
        ans %= MOD;
    }
    cout << ans << endl;
}
