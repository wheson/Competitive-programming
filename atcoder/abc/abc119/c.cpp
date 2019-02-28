#include <bits/stdc++.h>
//#define int long long

using namespace std;
using LL = long long;

#define FOR(i, a, n) for(int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)

#define pb(a) push_back(a)
#define all(x) (x).begin(),(x).end()

const int INF = (int)1e9;
const LL INFL = (LL)1e19;
const int MOD = (int)1e9 + 7;

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, a, b, c;
    cin >> n >> a >> b >> c;
    vector<int> l(n);
    REP(i, n) cin >> l[i];
    vector<int> aa(1 << n), bb(1 << n), cc(1 << n);
    FOR(i, 1, 1 << n){
        int sum = -10;
        int h = 0;
        REP(j, n){
            if(i & (1 << j)){
                sum += 10;
                h += l[j];
            }
        }
        aa[i] = sum + abs(h - a);
        bb[i] = sum + abs(h - b);
        cc[i] = sum + abs(h - c);
    }

    int ans = INF;
    FOR(i, 1, 1 << n) FOR(j, 1, 1 << n) FOR(k, 1, 1 << n){
        bool flag = false;
        if(i & j || i & k || j & k) continue;
        //cout << bitset<8>(i) << " " << bitset<8>(j) << " " << bitset<8>(k) << " " << aa[i] + bb[j] + cc[k] << endl;
        ans = min(ans, aa[i] + bb[j] + cc[k]);
    }
    cout << ans << endl;
}