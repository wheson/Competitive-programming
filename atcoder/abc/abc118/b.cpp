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

    int n, m;
    cin >> n >> m;
    vector<int> foods(m, 0);
    REP(i, n){
        int k;
        cin >> k;
        REP(j, k){
            int a;
            cin >> a;
            foods[a-1]++;
        }
    }
    int ans = 0;
    REP(i, m) if(foods[i] == n) ans++;
    cout << ans << endl;
}