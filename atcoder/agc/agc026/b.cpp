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
const int MOD = 1e9 + 7;

int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};
// gcd: 最大公約数, lcm: 最小公倍数
template<typename T>
T euclidean(T a, T b){
    if(a < b) swap(a, b);
    T r = a % b;
    while(r != 0){
        a = b; b = r; r = a % b;
    }
    return b;
}
template<typename T>
T gcd(T a, T b){
    return euclidean(a, b);
}
template<typename T>
T lcm(T a, T b){
    T g = gcd(a, b);
    return a / g * b;
}
signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    REP(i, t){
        LL a, b, c, d;
        cin >> a >> b >> c >> d;
        if(b > d || a < b){
            cout << "No" << endl;
            continue;
        }
        if(c >= b){
            cout << "Yes" << endl;
            continue;
        }

        LL y = gcd(d, b);
        LL x = a % y;
        cout << (b - y + x > c ? "No" : "Yes") << endl;
    }
}
