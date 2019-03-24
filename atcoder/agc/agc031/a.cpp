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

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    string s;
    int n;
    cin >> n >> s;

    LL ans = 1;
    map<char, LL> mp;
    REP(i, n) mp[s[i]]++;

    for (int j = 0; j < 26; j++)
    {
        ans = ans * (mp[(char)('a' + j)] + 1) % MOD;
    }

    cout << (ans + MOD - 1) % MOD << endl;
}