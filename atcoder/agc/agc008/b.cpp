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
int n, k;
vector<int> a;
/**********************************************/

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> k;
    a.resize(n);
    REP(i, n) cin >> a[i];
    
    vector<int> ruiseki1(n), ruiseki2(n);
    ruiseki1[0] = a[0];
    REP(i, n-1){
        ruiseki1[i+1] = ruiseki1[i] + a[i+1];
    }
    ruiseki2[0] = max(0LL, a[0]);
    REP(i, n-1){
        ruiseki2[i+1] = ruiseki2[i] + max(0LL, a[i+1]);
    }
    
    int ans = -INFL;
    REP(i, n-k+1){
        int range1 = max(0LL, ruiseki1[i+k-1] - (i == 0 ? 0 : ruiseki1[i-1]));
        int range2 = (i == 0 ? 0 : ruiseki2[i-1]);
        int range3 = (i == n-k ? 0 : ruiseki2[n-1] - ruiseki2[i+k-1]);
        ans = max(ans, range1 + range2 + range3);
    }
    cout << ans << endl;
}
