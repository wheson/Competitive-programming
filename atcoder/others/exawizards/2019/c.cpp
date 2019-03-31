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
    
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;

    vector<char> t(q), d(q);
    REP(i, q) cin >> t[i] >> d[i];

    auto f = [&](int m, int num){
        REP(i, q)
        {
            if(t[i] == s[m])
            {
                m += (d[i] == 'L' ? -1 : 1);
            }
            if(m == num) return true;
            else if(m >= n) return false;
            else if(m < 0) return false;
        }
        return false;
    };

    int r, l;
    int ok = 0, ng = n+1;
    while(abs(ok - ng) > 1)
    {
        int mid = (ok + ng) / 2;
        if(f(mid-1, -1)) ok = mid;
        else ng = mid;
    }
    l = ok;

    ok = 0, ng = n+1;
    while(abs(ok - ng) > 1)
    {
        int mid = (ok + ng) / 2;
        if(f(n - mid, n)) ok = mid;
        else ng = mid;
    }
    r = ok;
    cout << max(0, n - l - r) << endl;
}