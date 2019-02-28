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

    int l;
    cin >> l;
    vector<int> a(l);
    REP(i, l) cin >> a[i];

    vector<int> inp(l+1, 0LL);
    vector<bool> link(l+1, false);
    REP(i, l){
        inp[i] += a[i]; inp[i+1] += a[i];
        if(a[i] > 0) {
            link[i] = true;
        }
    }

    vector<int> odd(l+2, 0LL);
    REP(i, l+1){
        if(inp[i] % 2 == 1) odd[i+1] = odd[i] + 1;
        else odd[i+1] = odd[i];
    }
    vector<int> ruiseki(l+1, 0LL);
    REP(i, l){
        ruiseki[i+1] = ruiseki[i] + a[i];
    }

    LL ans = 0;
    int index = 0;
    REP(i, l){
        if(!link[i]){
            int sum = ruiseki[i+1] - ruiseki[index];
            ans = max(ans, sum - max(0LL, odd[i+1] - odd[index] - 2) / 2LL);
            index = i+1;
        }else if(i == l-1){
            int sum = ruiseki[l] - ruiseki[index];
            ans = max(ans, sum - max(0LL, odd[l+1] - odd[index] - 2) / 2LL);
        }
    }
    //REP(i, l+1) cout << inp[i] << endl;

    cout << ruiseki[l] - ans << endl;
}