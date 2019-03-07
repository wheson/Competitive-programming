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

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int a, b, k;
    cin >> a >> b >> k;

    vector<int> ans;
    REP(i, 100) if(a % (i+1) == 0 && b % (i+1) == 0) ans.pb(i+1);
    cout << ans[ans.size() - k] << endl;

}