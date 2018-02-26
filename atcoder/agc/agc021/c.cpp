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
int n, m, a, b;
/**********************************************/

signed main(){
    cin >> n >> m >> a >> b;
    int nn = n, mm = m;
    if(m / 2 * n <= a){
        cout << "NO" << endl;
        return 0;
    }
    
    nn -= a / n;
    if(m % 2)

}
