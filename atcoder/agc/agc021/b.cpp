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
#include <float.h>
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
int n;
vector<LL> x, y;
LL max_dis = 0;
int confirm_index[305];
double min_dis[100005];
double index_dis[305][100005];
/**********************************************/

signed main(){
    cin >> n;
    x.resize(n); y.resize(n);

    REP(i, n) cin >> x[i] >> y[i];
    
    REP(i, n){
        max_dis = max(max(max_dis, abs(x[i])), abs(y[i]));
    }
    max_dis = pow(max_dis, 2); 
    REP(i, 100000){
        min_dis[i] = DBL_MAX;
    }

    REP(i, 100000){
        REP(j, n){
            double cir_x = max_dis * cos((M_PI*(i+1))/100000);
            double cir_y = max_dis * sin((M_PI*(i+1))/100000);

            index_dis[j][i] = sqrt((cir_x - x[j]) * (cir_x - x[j]) + (cir_y - y[j]) * (cir_y - y[j]));
            min_dis[i] = min(min_dis[i], index_dis[j][i]);
        }
    }
    
    REP(i, n){
        int x = 0;
        REP(j, 100000){
            if(index_dis[i][j] == min_dis[j]) x++;
        }

        confirm_index[i] = x;
    }
    /*REP(i, n){
        cout << confirm_index[i] << endl;
    }
    */
    REP(i, n){
        printf("%.10f\n" ,confirm_index[i] / 100000.0);
    }
}
