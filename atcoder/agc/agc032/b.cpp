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
    if(n % 2 == 0)
    {
        cout << n * (n-1) / 2 - n / 2 << endl;
        REP(i, n)
        {
            REP(j, n)
            {
                if(i == j || n - i - 1 == j || i >= j) continue;
                cout << i + 1 << " " << j + 1 << endl;
            }
        }
    }
    else
    {
        cout << n * (n-1) / 2 - n / 2 << endl;
        REP(i, n)
        {
            REP(j, n)
            {
                if(i == j || n - i - 2 == j || i >= j) continue;
                cout << i + 1 << " " << j + 1 << endl;
            }
        }
    }
    
}