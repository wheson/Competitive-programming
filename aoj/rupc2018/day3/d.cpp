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
#include <bitset>
#include <climits>
#define REP(i, n) for(LL i = 0;i < n;i++)
#define REPR(i, n) for(LL i = n;i >= 0;i--)
#define FOR(i, m, n) for(LL i = m;i < n;i++)
#define FORR(i, m, n) for(LL i = m;i >= n;i--)
#define pb(a) push_back(a)
#define all(x) (x).begin(),(x).end()
#define INF (int)1e9
#define INFL (LL)1e15
#define MOD 1000000007
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

//#define int long long
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
int pre_prime = 0;
LL ans = 0;
int n;
vector<int> q;
bool flag = false;
/**********************************************/

LL kaijou(LL n){
    LL ret = 1;
    REP(i, n){
        ret = ret * 2 % MOD;
    }

    return ret;
}

signed main(){
    cin >> n;
    q.resize(n);
    REP(i, n) cin >> q[i];
    if(n == 1){
        if(!isprime((LL)q[0]) || q[0] < pre_prime){
            cout << 0 << endl;
            return 0;
        }else{
            cout << 1 << endl;
            return 0;
        }
    }
    
    LL dp[100009][2];
    memset(dp,0,sizeof(dp));
    REP(i, n-1){
        if(!isprime(q[i]) && !isprime(q[i+1])){
            cout << 0 << endl;
            return 0;
        }
    }
    if(isprime(q[0]))dp[0][0]=1;
    if(isprime(q[0]))dp[1][1]=1;
    if(dp[0][0]==0 && dp[1][1] == 0){
        cout << 0 << endl;
        return 0;
    }
    for(int i=1;i<n;i++){
        if(isprime(q[i])){
            dp[i][1]+=dp[i-1][0];
            if(dp[i-1][1]&&q[i-1]*q[i-2]<q[i])dp[i][0]+=dp[i-1][1];

            if(q[i-1]<q[i])dp[i][0]+=dp[i-1][0];
            //dp[i][1]+=dp[i-1][1];
        }
        else{
            if(q[i-1]*q[i-2]<q[i])dp[i][1]+=dp[i-1][0];
            //dp[i][0]+=dp[i-1][1];

            //dp[i][1]+=dp[i-1][0];
            //dp[i][1]+=dp[i-1][1];
        }
    }
    cout << dp[n-1][1] + dp[n-1][0] << endl;

}
