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
const LL INFL = (LL)1e19;
const int MOD = 1e9 + 7;

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;
    vector<P> p(n);
    REP(i, n){
        int a, b;
        cin >> a >> b;
        p[i] = make_pair(a, b);
    } 
    sort(all(p));

    LL ans = 0;
    REP(i, n){
        if(m == 0) break;
        REP(j, p[i].second){
            if(m == 0) break;
            ans += p[i].first;
            m--;
        }
    }
    cout << ans << endl;

}