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
    vector<int> a;
    int m = 0, p = 0;
    for(int i = s.size()-1; i >= 0; i--)
    {
        if(s[i] == '+') p++;
        else if(s[i] == '-') m++;
        else a.push_back(p - m);
    }
    sort(all(a));
    REP(i, a.size()){
        if(i < a.size()/2) ans -= a[i];
        else ans += a[i];
    }
    cout << ans << endl;
}