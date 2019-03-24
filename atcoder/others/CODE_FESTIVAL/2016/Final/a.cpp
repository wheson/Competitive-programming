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
const LL INFL = (LL)1e19;
const int MOD = 1e9 + 7;

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n; cin >> n;
    vector<int> a(n), b(n);
    REP(i, n) cin >> a[i];
    REP(i, n) cin >> b[i];

    vector<P> c;
    REP(i, n){
        c.push_back(make_pair(a[i], 0));
        c.push_back(make_pair(b[i], 1));
    }
    sort(all(c));

    int cnt[2] = {0};
    
    LL ans = 1;
    for(auto x : c){
        if (cnt[x.second xor 1] != 0)
        {
            ans = ans * cnt[x.second xor 1] % MOD;
            cnt[x.second xor 1]--;
        }
        else
        {
            cnt[x.second]++;
        }
    }
    cout << ans << endl;
}