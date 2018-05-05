#include <bits/stdc++.h>
#define int long long

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

/*************** using variables ***************/
LL n;
/**********************************************/
// gcd: 最大公約数, lcm: 最小公倍数
LL euclidean(LL a, LL b){
    if(a < b) swap(a, b);
    LL r = a % b;
    while(r != 0){
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}
LL gcd(LL a, LL b){
    return euclidean(a, b);
}
LL lcm(LL a, LL b){
    LL g = gcd(a, b);
    return a / g * b;
}
signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n;
    
    for(LL x = 1; x <= 3500; x++){
        for(LL y = 1; y <= 3500; y++){
            LL g = (x*y)*4 - n*y - n*x;
            if(g > 0 && (n*x*y) % g == 0){
                cout << x << " " << y << " " << (n*x*y) / g << endl;
                return 0;
            }
        }
    }

}
