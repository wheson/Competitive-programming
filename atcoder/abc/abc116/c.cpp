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

    int n;
    cin >> n;
    vector<int> h(n);
    REP(i, n) cin >> h[i];

    int ans  = 0;
    REP(i, n){
        while(h[i] > 0){
            ans++;
            h[i]--;
            FOR(j, i+1, n){
                if(h[j] <= 0) break;
                h[j]--;
            }
        }
    }
    cout << ans << endl;
}