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

/*************** using variables **************/
int l, x, y, s, d;
double ans;
/**********************************************/

// 時計回りの距離
int dis1(int s, int g){
    int ret;
    if(s <= g) ret = g - s;
    else ret = l-s + g;
    return ret;
}

// 反時計回りの距離
int dis2(int s, int g){
    int ret;
    if(g <= s) ret = s - g;
    else ret = s + l-g;
    return ret;
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> l >> x >> y >> s >> d;
    ans = (double)dis1(s, d) / (y+x);
    if(y-x > 0) ans = min(ans, (double)dis2(s, d) / (y-x));
    printf("%.9f\n" ,ans);
}
