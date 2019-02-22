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

    int n, a, b;
    cin >> n >> a >> b;
    vector<int> p(n);
    REP(i, n) cin >> p[i];

    int c[3] = {0};
    REP(i, n){
        if(p[i] <= a) c[0]++;
        else if(p[i] <= b) c[1]++;
        else c[2]++;
    }
    cout << min({c[0], c[1], c[2]}) << endl;
}