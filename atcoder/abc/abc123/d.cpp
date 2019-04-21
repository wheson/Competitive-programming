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

signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int x, y, z, k;
    cin >> x >> y >> z >> k;
    vector<LL> a(x), b(y), c(z);
    REP(i, x) cin >> a[i];
    REP(i, y) cin >> b[i];
    REP(i, z) cin >> c[i];

    vector<LL> ab(x*y);
    REP(i, x) REP(j, y) ab[i*y+j] = a[i] + b[j];

    sort(all(ab), greater<LL>());
    sort(all(c), greater<LL>());
    ab.push_back(0);
    c.push_back(0);

    int abi = 0, ci = 0;
    vector<LL> ans;

    while(ans.size() < 100000000)
    {
        
        if(ab[abi] < c[ci]){
            REP(i, ab.size() - abi)
            {
                ans.push_back(ab[i] + c[ci]);
            }
            ci++;
        } 
        else abi++;
        {
            REP(i, c.size() - ci)
            {
                ans.push_back(ab[abi] + c[i]);
            }
            abi++;
        }
    }
    sort(all(ans), greater<LL>());
    REP(i, k)
    {
        cout << ans << endl;
    }
}