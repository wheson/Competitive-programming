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
    vector<int> ac(n+1, 0);
    FOR(i, 1, n){
        if(s[i-1] == 'A' && s[i] == 'C') ac[i] = ac[i-1] + 1;
        else ac[i] = ac[i-1];
    }
    REP(i, q)
    {
        int l, r;
        cin >> l >> r;
        cout << ac[r-1] - ac[l-1] << endl;
    }
}