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
const LL INFL = (LL)1e18;
const int MOD = (int)1e9 + 7;

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, t, a;
    cin >> n >> t >> a;
    vector<int> h(n);
    REP(i, n) cin >> h[i];

    a *= 1000; t *= 1000;
    int ans = INFL, ans_i = 1;
    REP(i, n){
        if(ans > abs(a - (t - h[i] * 6))){
            ans = abs(a - (t - h[i] * 6));
            ans_i = i+1;
        }
    }
    cout << ans_i << endl;
}