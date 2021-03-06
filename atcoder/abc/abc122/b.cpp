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
    
    string s;
    cin >> s;
    int ans = 0;
    int cur = 0;
    REP(i, s.size())
    {
        if(s[i] == 'A' || s[i] == 'C' || s[i] == 'G' || s[i] == 'T') cur++;
        else cur = 0;
        ans = max(ans, cur);
    }
    cout << ans << endl;
}