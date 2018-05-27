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
double a, b;
string dir[] = {"N", "NNE", "NE", "ENE", "E", "ESE", "SE", "SSE", "S", "SSW", "SW", "WSW", "W", "WNW", "NW", "NNW", "C"};
/**********************************************/

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin >> a >> b;
    int dir_n = (int)((a + 112.5) / 225) % 16;
    
    b *= 10;
    b /= 60.0;
    b = (int)(b+0.5) / 10.00;
    int v_n;
    if(b <= 0.2) v_n = 0;
    else if(b <= 1.5) v_n = 1;
    else if(b <= 3.3) v_n = 2;
    else if(b <= 5.4) v_n = 3;
    else if(b <= 7.9) v_n = 4;
    else if(b <= 10.7) v_n = 5;
    else if(b <= 13.8) v_n = 6;
    else if(b <= 17.1) v_n = 7;
    else if(b <= 20.7) v_n = 8;
    else if(b <= 24.4) v_n = 9;
    else if(b <= 28.4) v_n = 10;
    else if(b <= 32.6) v_n = 11;
    else v_n = 12;
    if(v_n == 0) dir_n = 16;
    cout << dir[dir_n] << " " << v_n << endl;
}
