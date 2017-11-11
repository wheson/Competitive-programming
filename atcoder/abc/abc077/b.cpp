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
vector<LL> sosuu;
int ans = 1;
/**********************************************/
template<typename IntType>
IntType IntSquare(const IntType num, bool isCheck = false)
{
    const static bool bad512[512] =
    {
        0, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1,
        1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1,
        0, 1, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1,
        1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1,
        1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1,
        1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1,
        0, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1,
        1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1,
        0, 1, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1,
        1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1,
        1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1,
        1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1,
        0, 0
    };
 
    // 平方数チェックする？
    if (isCheck) {
        IntType t = num & 0xF;
        if (t > 9)
            return 0;
 
        if (t == 2 || t == 3 || (t <= 5 && t >= 8) )
            return 0;
 
 
        if (bad512[num % 510])
            return 0;
    }
 
    //---------------------------------------
    IntType place = (IntType)0x40 << ((sizeof(IntType) - 1) << 3);
    IntType tmp = num;
    while (place > num) place >>= 2;
 
    IntType root = 0;
    while (place)
    {
        if (tmp >= root + place)
        {
            tmp -= root + place;
            root += place << 1;
        }
        root >>= 1;
        place >>= 2;
    }
 
    if (isCheck) {
        if ((root * root) == num)
            return root;
        return 0;
    }
 
    return root;
}

int main(){
    cin >> n;

    while(n){
        int t = IntSquare(n, true);
        if(t != 0) break;
        n--;
    }

    cout << n << endl;
}
