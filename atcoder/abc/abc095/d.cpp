#include <bits/stdc++.h>
#define int long long

using namespace std;
using LL = long long;
using P = pair<int, int>;

#define FOR(i, a, n) for(int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)

#define pb(a) push_back(a)
#define all(x) (x).begin(),(x).end()

const int INF = (int)1e9;
const LL INFL = (LL)1e15;
const int MOD = 1e9 + 7;

int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

/*************** using variables **************/
LL n, c;
vector<LL> x, rx, v;
vector<LL> ruiseki;
vector<LL> ruiseki1, ruiseki2;
/**********************************************/

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin >> n >> c;
    x.resize(n);
    rx.resize(n);
    v.resize(n);
    REP(i, n) cin >> x[i] >> v[i];
    REP(i, n) rx[i] = c-x[i];
    reverse(all(rx));

    ruiseki.resize(n+1);
    ruiseki[0] = 0;
    REP(i, n){
        ruiseki[i+1] = ruiseki[i] + v[i];
    }
    
    vector<LL> ans1(n, 0);
    ans1[0] = max(0LL, ruiseki[1]-x[0]);
    FOR(i, 1, n){
        ans1[i] = max(ans1[i-1], ruiseki[i+1]-x[i]);
    }
    
    vector<LL> ans2(n, 0);
    ans2[n-1] = max(0LL, v[n-1] - rx[0]);
    FOR(i, 1, n){
        ans2[n-i-1] = max(ans2[n-i], ruiseki[n]-ruiseki[n-i-1] - rx[i]);
    }
    
    vector<LL> ans3(n, 0);
    REP(i, n-1){
        //cout << i << ": " << ans1[i] << " " << ans2[i+1] - x[i] << endl;
        ans3[i] = max(ans1[i], ans1[i] + ans2[i+1] - x[i]);
    }
    ans3[n-1] = ans1[n-1];

    vector<LL> ans4(n, 0);
    for(int i = n-1; i > 0; i--){
        //cout << i << ": " << ans2[i] << " " << ans1[i-1] - rx[n-1-i] << endl;
        ans4[n-i-1] = max(ans2[i], ans2[i] + ans1[i-1] - rx[n-i-1]);
    }
    ans4[n-1] = ans2[n-1];

    LL ans = 0;
    REP(i, n) ans = max(ans, max(max(ans1[i], ans2[i]), max(ans3[i], ans4[i])));
    cout << ans << endl;
}
