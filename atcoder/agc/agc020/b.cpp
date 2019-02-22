#include <bits/stdc++.h>
#define int long long

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

    int k;
    cin >> k;
    vector<int> a(k), b(k);
    REP(i, k) cin >> a[i];

    if(a[k-1] != 2){
        cout << -1 << endl;
        return 0;
    }

    LL ans1 = 2, ans2 = 2;
    b[k-1] = 2;
    for(int i = k-2; i >= 0; i--){
        if(a[i] > ans1 + a[i+1]-1) {
            cout << -1 << endl;
            return 0;
        }
        b[i] = a[i] * ceil(1.0 * b[i+1] / a[i]);
        //cout << ans1 << endl;
    }
    /*
    REP(i, k){
        cout << b[i] << " \n"[i == k-1];
    }
    */
    cout << b[0] << " " << b[0] + a[0]-1 << endl;

}
