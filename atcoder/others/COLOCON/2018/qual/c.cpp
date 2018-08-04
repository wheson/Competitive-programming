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
const LL INFL = (LL)1e18;
const int MOD = 1e9 + 7;

// gcd: 最大公約数, lcm: 最小公倍数
template<typename T>
T euclidean(T a, T b){
    if(a < b) swap(a, b);
    T r = a % b;
    while(r != 0){
        a = b; b = r; r = a % b;
    }
    return b;
}
template<typename T>
T gcd(T a, T b){
    return euclidean(a, b);
}
template<typename T>
T lcm(T a, T b){
    T g = gcd(a, b);
    return a / g * b;
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    LL a, b;
    cin >> a >> b;
    vector<LL> even, odd;
    REP(i, b-a+1){
        if((a + i) % 2 == 0) even.pb(a+i);
        else odd.pb(a+i);
    }
    
    LL ans = 0;
    int oddsz = odd.size(), evensz = even.size();
    for(int mask = 0; mask < (1 << oddsz); mask++){
        bool flag = true;
        REP(i, oddsz){
            if(mask & (1 << i)){
                REP(j, oddsz){
                    if(mask & (1 << j) && i != j && gcd(odd[i], odd[j]) != 1){
                        flag = false;
                    }
                }
            }
        }
        if(flag){
            ans++;
            REP(i, evensz){
                bool flag = true;
                REP(j, oddsz){
                    if(mask & (1 << j) && gcd(even[i], odd[j]) != 1){
                        flag = false;
                    }
                }
                if(flag) ans++;
            }
        }
    }
    cout << ans << endl;

}
