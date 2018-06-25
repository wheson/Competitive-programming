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

LL ketawa(LL a){
    LL ret = 0;
    while(a > 0) ret += a % 10, a /= 10;
    return ret;
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int k;
    cin >> k;
    LL a = 1, b = 1;
    REP(i, k){
        cout << a << endl;
        if(ketawa(a + b) * (a + b*10) < ketawa(a + b*10) * (a + b)) b *= 10;
        a += b;
    }
}
