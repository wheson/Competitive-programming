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

vector<int> ans;
void f(vector<int> a)
{
    if(a.empty()) return;
    int max_num = 0;
    REP(i, a.size())
    {
        if(i+1 == a[i]) max_num = i+1;
    }

    vector<int> b;
    ans.push_back(max_num);
    REP(i, a.size())
    {
        if(i+1 != max_num) b.push_back(a[i]);
    }
    if(max_num == 0)
    {
        ans.clear();
        return;
    }
    f(b);
}

signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    vector<int> a(n);
    
    REP(i, n) cin >> a[i];
    f(a);

    if(ans.empty())
    {
        cout << -1 << endl;
        return 0;
    }

    reverse(all(ans));
    REP(i, n)
    {
        cout << ans[i] << endl;
    }
}