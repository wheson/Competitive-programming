#include <bits/stdc++.h>
//#define int long long

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

bool isprime(LL x){
    if(x == 2) return true;
    if(x < 2 || x % 2 == 0) return false;
    LL i = 3;
    LL sqrtx = sqrt(x);
    while(i <= sqrtx){
        if(x % i == 0) return false;
        i += 2;
    }
    return true;
}
// maxまでの素数をvectorに入れて返す
vector<LL> eratos(LL max){
    vector<LL> primeVec;
    vector<bool> isprime;
    double sqrtmax = sqrt(max);
    isprime.resize(max + 1);
    isprime[0] = false; isprime[1] = false;
    FOR(i, 2, max + 1){
        isprime[i] = true;
    }
    FOR(i, 2, sqrtmax){
        if(isprime[i]){
            for(int j = 0; i * (j + 2) < max + 1; ++j){
                isprime[i * (j + 2)] = false;
            }
        }
    }
    REP(i, max + 1){
        if(isprime[i])  primeVec.pb(i);
    }
    return primeVec;
}

/*************** using variables ***************/
int n;
/**********************************************/

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n;
    vector<LL> sosuu_list = eratos(55555);
    vector<LL> ans;
    
    int cnt = 0;
    while(1){
        if(ans.size() >= n) break;

        if(sosuu_list[cnt] % 10 == 3) ans.pb(sosuu_list[cnt]);

        cnt++;
    
    }
    REP(i, n) cout << ans[i] << " ";
    cout << endl;
}
