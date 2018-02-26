#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <tuple>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <cstdio>
#include <numeric>
#define REP(i, n) for(LL i = 0;i < n;i++)
#define REPR(i, n) for(LL i = n;i >= 0;i--)
#define FOR(i, m, n) for(LL i = m;i < n;i++)
#define FORR(i, m, n) for(LL i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define pb(a) push_back(a)
#define all(x) (x).begin(),(x).end()
#define INF (LL)1e15
#define MOD 1000000007
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
typedef pair<LL, LL> LP;
typedef pair<int, P> PP;
typedef pair<LL, LP> LPP;
int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

LL change_div_mul_mod(LL divisor, LL mod_minus_2, LL mod){
    if(mod_minus_2 == 0) return 1;
    else if(mod_minus_2 % 2 == 0){
        LL d = change_div_mul_mod(divisor, mod_minus_2/2, mod);
        return (d * d) % mod;
    }else{
        return (divisor * change_div_mul_mod(divisor, mod_minus_2-1, mod)) % mod;
    }
}

//#define int long long

/*************** using variables ***************/
LL n;
string s;
/**********************************************/

int ctoi(char c){
    return (int)(c - '0');
}

signed main(){
    /*cin >> s;

    int z = s.size();
    int ans = 0;
    REP(i, z-1){
        ans += 9;
    }
    
    int ans2 = 0;
    REP(i, z){
        ans2 += ctoi(s[i]);
    }
    
    int ans3 = 0;
    REPR(i, z-1){
        if(ctoi(s[i]) != '9'){
            ans3 += 8;
        }else{
            ans3 += 9;
        }
    }
    cout << max(ans, ans2) << endl;
    
    */
    cin >> n;
    LL ans = 0;
    while(n > 0){
        if(n / 10 != 0 && n % 10 != 9){
            n -= 10;
            n += 9 - n % 10;
        }
        ans += n % 10;
        n /= 10;
    }

    cout << ans << endl;
}
