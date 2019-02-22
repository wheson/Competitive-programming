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

    int h, m, s, c1, c2;
    cin >> h >> m >> s >> c1 >> c2;

    // s1 := 1回目に秒針が分針を跨ぐ秒数
    int s1 = (m >= s ? m - s + 1 : 60 - s + m + 1);

    // m1 := 1回目に分針が時針を跨ぐ秒数
    int m1 = 60 * ()
}