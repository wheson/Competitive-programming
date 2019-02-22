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
const int MOD = (int)1e9 + 7;

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int x, y;
    cin >> x >> y;

    if(x < y) swap(x, y);
    while(x > 0 && y > 0){
        x -= 3, y -= 1;
        if(x < y) swap(x, y);
    }
    if(x == 0 && y == 0) cout << "Yes" << endl;
    else cout << "No" << endl;
}