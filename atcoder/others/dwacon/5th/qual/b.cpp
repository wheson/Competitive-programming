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
const LL INFL = (LL)1e18;
const int MOD = (int)1e9 + 7;

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    REP(i, n) cin >> a[i];

    LL ans = 0;
    vector<LL> vec;
    REP(i, n){
        LL sum = a[i];
        vec.pb(a[i]);
        FOR(j, i+1, n){
            sum += a[j];
            vec.pb(sum);
        }
    }

    sort(all(vec), greater<LL>());
    LL num = 0;
    for(int i = 60; i >= 0; i--){
        LL sum = (1LL << 60) - 1;
        int cnt = 0;
        REP(j, vec.size()){
            if((vec[j] & num) == num && vec[j] & (1LL << i)){
                sum &= vec[j];
                cnt++;
                if(cnt >= k) break;
            }
        }
        if(cnt >= k){
            num += 1LL << i;
        }
    }
    cout << num << endl;
}
