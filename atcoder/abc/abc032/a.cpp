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
#include <numeric>
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

LL euclidean(LL a, LL b){
    if(a < b) swap(a, b);
    LL r = a % b;
    while(r != 0){
        a = b;
        b = r;
        r = a % b;
    }

    return b;
}

LL gcd(LL a, LL b){
    return euclidean(a, b);
}

LL lcm(LL a, LL b){
    return a * b / gcd(a, b);
}

/*************** using variables ***************/
int a, b, n;
/**********************************************/

int main(){
    cin >> a >> b >> n;
    int x = lcm(a, b);
    int i = 2;
    while(x < n){
        if(x * i >= n){
            x *= i;
            break;
        }
        i++;
    }

    cout << x << endl;
}
