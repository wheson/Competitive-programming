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
    
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    vector<int> b;
    b.push_back(1);

    REP(i, n-1)
    {
        if(s[i+1] == s[i]) b.back()++;
        else b.push_back(1);
    }
    REP(i, b.size()) cout << b[i] << endl;

    vector<int> ruiseki(b.size()+1, 0);
    REP(i, b.size())
    {
        ruiseki[i+1] += ruiseki[i] + b[i];
    }

    if (b.size() / 2 + b.size() % 2 <= k)
    {
        cout << n << endl;
        return 0;
    }

    int ans = 0;
    REP(i, n)
    {
        if (i + k * 2 > b.size()) break;
        ans = max(ruiseki[i + k * 2] - ruiseki[i], ans);
    }
    cout << ans << endl;
}