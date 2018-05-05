#include <bits/stdc++.h>
#define int long long

using namespace std;
using LL = long long;
using P = pair<int, int>;
using Tapris = tuple<int, int, int>;

#define FOR(i, a, n) for(int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)

#define pb(a) push_back(a)
#define all(x) (x).begin(),(x).end()

const int INF = (int)1e9;
const LL INFL = (LL)1e15;
const int MOD = 1e9 + 7;

int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

/*************** using variables ***************/
int n;
vector<int> a, ruiseki;
/**********************************************/

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n;
    a.assign(n, 0);
    ruiseki.assign(n+1, 0);
    REP(i, n) cin >> a[i];
    
    FOR(i, 1, n+1){
        ruiseki[i] = ruiseki[i-1] + a[i-1];
    }

    map<int, int> mp;

    int ans = 0;
    REP(i, n+1){
        if(mp.count(ruiseki[i])) ans += mp[ruiseki[i]];
        mp[ruiseki[i]]++;
    }
    cout << ans << endl;
}
