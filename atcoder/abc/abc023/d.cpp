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
    
    int n;
    cin >> n;
    vector<LL> h(n), s(n);
    REP(i, n) cin >> h[i] >> s[i];
    LL ok = 0, ng = -1;
    REP(i, n)
    {
        ok = max(ok, h[i]+s[i]*(n-1));
    }
    while(abs(ok - ng) > 1){
        LL mid = (ok + ng) / 2;
        vector<double> lim;
        REP(i, n)
        {
            lim.push_back(1.0*(mid - h[i])/s[i]);
        }
        sort(all(lim));
        bool flag = true;
        REP(i, n) flag = flag && lim[i] >= i;
        if(flag) ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
}