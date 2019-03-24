#include <bits/stdc++.h>
//#define int long long

using namespace std;
using LL = long long;
using P = pair<int, int>;

#define FOR(i, a, n) for (int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)

#define pb(a) push_back(a)
#define all(x) (x).begin(), (x).end()

const int INF = (int)1e9;
const LL INFL = (LL)1e19;
const int MOD = 1e9 + 7;

signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    int ok = 0, ng = n;
    string f;

    cout << 0 << endl;
    cin >> f;
    if (f == "Vacant")
        return 0;
    int se = f == "Male" ? 0 : 1;

    while (abs(ok - ng) > 1)
    {
        int mid = (ok + ng) / 2;
        string re;
        cout << mid << endl;
        cin >> re;
        if (re == "Vacant")
        {
            return 0;
        }
        int cur = re == "Male" ? 0 : 1;
        if ((mid - ok) % 2 == 0)
        {
            if (cur == se)
                ok = mid, se = cur;
            else
                ng = mid;
        }
        else
        {
            if (cur != se)
                ok = mid, se = cur;
            else
                ng = mid;
        }
    }
    cout << ok << endl;
}