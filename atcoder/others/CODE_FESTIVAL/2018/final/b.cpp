#include <bits/stdc++.h>
//#define int long long

using namespace std;
using LL = long long;

#define FOR(i, a, n) for(int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)

#define pb(a) push_back(a)
#define all(x) (x).begin(),(x).end()

const int INF = (int)1e9;
const LL INFL = (LL)1e19;
const int MOD = (int)1e9 + 7;

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    REP(i, m) cin >> a[i];

    vector<double> logfact(n+1, 0);
    REP(i, n){
        logfact[i+1] = logfact[i] + log10(i+1);
    }

    double ans = n * log10(m) - logfact[n];
    REP(i, m){
        ans += logfact[a[i]];
    }
    cout << ceil(ans) << endl;
}