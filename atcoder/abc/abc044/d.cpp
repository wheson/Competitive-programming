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
const int MOD = (int)1e9 + 7;

LL f(LL b, LL n){
    LL sum = 0;
    while(n > 0){
        sum += n % b;
        n /= b;
    }
    return sum;
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    LL n, s;
    cin >> n >> s;

    LL ans = INFL;
    // s == n の時はn+1しかない
    if(s == n){
        cout << n+1 << endl;
        return 0;
    }

    // s > n の時は作れない
    if(s > n){
        cout << -1 << endl;
        return 0;
    }

    // √n以下の値で全探索
    for(LL i = 2; i*i <= n; i++){
        if(s == f(i, n)){
            ans = min(ans, i);
        }
    }

    // pb + q = n
    // p + q = s
    // pb + (s - p) = n
    // b = (n - s + p) / p
    // b = (n - s) / p + 1
    // bは√n以上なのでpは√n未満になる
    for(LL p = 1; p*p < n; p++){
        LL b = (n - s) / p + 1;
        if(b < 2) continue;
        if(s == f(b, n)){
            ans = min(ans, b);
        }
    }
    cout << (ans != INFL ? ans : -1) << endl;
}