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
    
    int n, m;
    cin >> n;
    vector<int> x(n);
    REP(i, n) cin >> x[i];
    cin >> m;
    vector<int> a(m);
    REP(i, m) cin >> a[i];

    REP(i, m)
    {
        if(x[a[i]-1] == 2019) continue;
        bool flag = true;
        REP(j, n){
            if(a[i] - 1 == j) continue;
            if(x[a[i] - 1]+1 == x[j]) flag = false;
        }
        if(flag) x[a[i]-1] += 1;
    }
    REP(i, n) cout << x[i] << endl;
}