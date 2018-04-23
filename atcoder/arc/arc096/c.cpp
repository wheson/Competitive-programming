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

#define int long long

/*************** using variables ***************/
int a, b, c;
int x, y;
/**********************************************/

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin >> a >> b >> c >> x >> y;
    
    LL ans = 0;
  /* 
    if(a + b >= c*2 && a >= c*2 && b >= c*2){
        ans += max(x, y) * (c*2);
    }else if(a + b >= c*2 && a >= c*2){
        ans += c*2 * x;
        ans += min(0LL, y-x) * b;
    }else if(a + b >= c*2 && b >= c*2){
        ans += c*2 * y;
        ans += min(0LL, x-y) * a;
    }else if(a + b >= c*2){
        ans += c*2 * min(x, y);
        if(x > y) ans += a*(x-y);
        else ans += b*(y-x);
    }else{
        ans = a*x + b*y;
    }
    */

    if(x > y){
        ans = min(min(a*x+b*y, c*x*2),c*y*2 + a*(x-y));
    }else{
        ans = min(min(a*x+b*y, c*y*2),c*x*2 + b*(y-x));
    }
    cout << ans << endl;
}
