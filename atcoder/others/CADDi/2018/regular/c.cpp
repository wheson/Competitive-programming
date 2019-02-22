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

    LL n, p;
    cin >> n >> p;
    map<int, int> mp;
    LL ori = p;
    for(int i = 2; i*i <= p; i++){
        while(p % i == 0){
            mp[i]++;
            p /= i;
        }
    }
    if(p != 0) mp[p]++;

    LL ans = 1;
    for(auto x : mp){
        while(x.second >= n){
            ans *= x.first;
            x.second -= n;
        }
    }

    cout << ans << endl;
}