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
const int MOD = 998244353;

signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> w(n+1), b(n+1);
    REP(i, n)
    {
        w[i+1] = w[i] + (s[i] == '.' ? 1 : 0);
        b[i+1] = b[i] + (s[i] == '#' ? 1 : 0);
    }

    int a = INF;
    REP(i, n+1)
    {
        a = min(a, b[i] + w[n] - w[i]);
    }
    cout << a << endl;

}