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

    int n;
    cin >> n;
    vector<int> a(n), b(n);
    REP(i, n) cin >> a[i] >> b[i];

    int m;
    cin >> m;
    vector<int> t(m);
    REP(i, m) cin >> t[i];

    vector<pair<int, int>> plan(n);
    REP(i, n) plan[i] = make_pair(a[i], b[i]);
    sort(all(plan));
    REP(i, n) a[i] = plan[i].first, b[i] = plan[i].second;

    REP(i, m){
        int index = (int)(lower_bound(all(a), t[i]) - a.begin());
        if(index != n && index != 0){
            cout << min(b[index], b[index-1] + t[i] - a[index-1]) << endl;
        }else if(index == n){
            cout << b[index-1] + t[i] - a[index-1] << endl;
        }else{
            cout << b[index] << endl;
        }
    }
}