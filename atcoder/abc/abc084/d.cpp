#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <tuple>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <cstdio>
#define REP(i, n) for(LL i = 0;i < n;i++)
#define REPR(i, n) for(LL i = n;i >= 0;i--)
#define FOR(i, m, n) for(LL i = m;i < n;i++)
#define FORR(i, m, n) for(LL i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define pb(a) push_back(a)
#define all(x) (x).begin(),(x).end()
#define INF 999999999
#define MOD 1000000007
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
typedef pair<LL, LL> LP;
typedef pair<int, P> PP;
typedef pair<LL, LP> LPP;
int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

/*************** using variables ***************/
int q;
vector<int> l, r;
vector<LL> sosuu_list, sosuu2_list;
/**********************************************/

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
 

int solve(int l, int r){
    int ans = 0;
    
    auto itr = lower_bound(sosuu2_list.begin(), sosuu2_list.end(), l);
    auto itr2 = upper_bound(sosuu2_list.begin(), sosuu2_list.end(), r); 
    for(; itr < itr2; itr++){
        ans++;
    } 

    return ans;
}

int main(){
    cin >> q;
    l.resize(q);
    r.resize(q);
    REP(i, q){
        cin >> l[i] >> r[i];
    }
    
    sosuu_list = eratos(100000);
    REP(i, sosuu_list.size()){
        if(isprime((sosuu_list[i]+1)/2)) sosuu2_list.pb(sosuu_list[i]);
    }

    REP(i, q){
        cout << solve(l[i], r[i]) << endl;
    }
}
