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
const LL INFL = (LL)1e19;
const int MOD = 1e9 + 7;

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    REP(i, n) cin >> a[i];
    vector<LL> ruiseki(n+1, 0), half_ruiseki(n+1, 0);
    REP(i, n) ruiseki[i+1] += ruiseki[i] + a[i];
    REP(i, n){ 
        if(n % 2 == 0 && i % 2 != 0) half_ruiseki[i+1] += half_ruiseki[i] + a[i];
        else if(n % 2 == 1 && i % 2 != 1) half_ruiseki[i+1] += half_ruiseki[i] + a[i];
        else half_ruiseki[i+1] += half_ruiseki[i];
    }

    REP(i, q){
        int x;
        cin >> x;
        auto f = [&](int m){
            
            return true;
        };
        int ok = n-1, ng = 0;
        while(abs(ok - ng) > 1){
            int mid = (ok + ng) / 2;
            if(f(mid)) ok = mid;
            else ng = mid;
        }
        LL ans = ruiseki[n] - ruiseki[ok-1] + half_ruiseki[max(n - (n - ok)*2, 0)];
    }
}