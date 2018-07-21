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
const LL INFL = (LL)1e18;
const int MOD = 1e9 + 7;

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> d(n);
    REP(i, n) cin >> d[i];
    int m;
    cin >> m;
    vector<int> t(m);
    REP(i, m) cin >> t[i];

    map<int, int> mp1, mp2;
    REP(i, m) mp1[t[i]]++;
    REP(i, n) mp2[d[i]]++;
    int sum = 0;
    for(auto x : mp1){
        sum += max(x.second - mp2[x.first], 0);
    }

    cout << (sum == 0 ? "YES" : "NO") << endl;
}
