#include <bits/stdc++.h>
#define int long long

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
    vector<int> a(n), b(n), d(n);
    REP(i, n) cin >> a[i];
    REP(i, n) cin >> b[i];

    LL sum1 = 0, sum2 = 0;
    REP(i, n){
        sum1 += a[i];
        sum2 += b[i];
    }

    if(sum1 < sum2){
        cout << -1 << endl;
        return 0;
    }


    REP(i, n){
        d[i] = a[i] - b[i];
    }

    vector<int> plus, minus;
    REP(i, n){
        if(d[i] < 0) minus.pb(-d[i]);
        else plus.pb(d[i]);
    }

    LL minus_sum = 0;
    REP(i, minus.size()){
        minus_sum += minus[i];
    }
    sort(all(plus), greater<int>());
    vector<LL> ruiseki(plus.size()+1);
    REP(i, plus.size()) ruiseki[i+1] += ruiseki[i] + plus[i];

    int ans = minus.size();
    REP(i, ruiseki.size()){
        if(minus_sum > ruiseki[i]) ans++;
    }
    cout << ans << endl;
}