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
#define SORT(v, n) sort(v, v+n)
#define VSORT(v) sort(v.begin(), v.end())
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
int n;
int r[1005];
/**********************************************/

int main(){
    cin >> n;
    REP(i, n) cin >> r[i];
    sort(r, r+n, std::greater<int>());

    if(n % 2 == 0){
        long double red = 0, white = 0;
        long double ans = 0;
        REP(i, n){
            if(i % 2 == 0){
                red = r[i] * r[i] * M_PI;
            }else{
                white = r[i] * r[i] * M_PI;
                ans += red - white;
            }
        }
        printf("%.7Lf\n", ans);
    }else{
        long double red = 0, white = 0;
        long double ans = 0;
        REP(i, n){
            if(i % 2 == 0){
                red = r[i] * r[i] * M_PI;
            }else{
                white = r[i] * r[i] * M_PI;
                ans += red - white;
            }
        }
        ans += red;
        printf("%.7Lf\n", ans);
    }

}
