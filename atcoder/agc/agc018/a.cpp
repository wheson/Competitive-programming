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
#define INF (LL)1e15
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
int n, k;
vector<string> ans_str = {"POSSIBLE", "IMPOSSIBLE"};
int a[100005];
/**********************************************/

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

int main(){
    cin >> n >> k;
    REP(i, n) cin >> a[i];
    
    int max_num = 0;
    REP(i, n){
        if(a[i] > max_num) max_num = a[i];
    }
    
    if(max_num < k){
        cout << ans_str[1] << endl;
        return 0;
    }

    int num = a[0];
    FOR(i, 1, n){
        num = gcd(a[i], num);
    }
    if(k % num == 0){
        cout << ans_str[0] << endl;
    }else{
        cout << ans_str[1] << endl;
    }
    
}
