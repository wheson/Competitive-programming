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

    int k, m;
    cin >> k >> m;
    vector<unsigned int> a(k), c(k);
    REP(i, k) cin >> a[i];
    REP(i, k) cin >> c[i];

    REP(i, m){
        unsigned int num = 0;
        REP(j, k){
            num = num xor (a[k+i-j-1] & c[j]);
        }
        a.pb(num);
    }
    //REP(i, m+k) cout << a[i] << " \n"[i == m+k-1];
}