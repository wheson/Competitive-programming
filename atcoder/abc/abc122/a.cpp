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
    
    char c;
    cin >> c;
    if(c == 'A') cout << 'T' << endl;
    if(c == 'T') cout << 'A' << endl;
    if(c == 'C') cout << 'G' << endl;
    if(c == 'G') cout << 'C' << endl;
}