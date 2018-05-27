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
const LL INFL = (LL)1e15;
const int MOD = 1e9 + 7;

int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

template <typename T>
vector<T> eratos(T n){
    vector<T> primeVec;
    vector<bool> isPrime;
    isPrime.assign(n+1, true);
    isPrime[0] = false; isPrime[1] = false;
    for(int p = 2; p*p <= n; p++){
        for(int i = p*2; i <= n; i += p) isPrime[i] = false;
    }
    for(int p = 2; p <= n; p++) if(isPrime[p]) primeVec.pb(p);
    return primeVec;
}

/*************** using variables **************/
int n;
/**********************************************/

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    vector<int> sosuu_list = eratos<int>(1000000);
    auto itr = lower_bound(all(sosuu_list), n);
    if(*itr == n) cout << "YES" << endl;
    else cout << "NO" << endl;
}
