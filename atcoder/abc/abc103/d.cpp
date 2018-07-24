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

    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m);
    REP(i, m) cin >> a[i] >> b[i];
    vector<P> p(m);
    REP(i, m){
        p[i].first = a[i], p[i].second = b[i];
    }

    vector<bool> hasi(n-1, false);
    sort(all(p));
    int l = p[0].first, r = p[0].second;
    int ans = 1;
    FOR(i, 1, m){
        if(p[i].first >= r){
            ans++;
            l = p[i].first, r = p[i].second;
            continue;
        }
        r = min(p[i].second, r);
    }
    
    cout << ans << endl;
} 
