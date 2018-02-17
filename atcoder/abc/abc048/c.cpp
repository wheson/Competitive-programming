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
int n;
LL x;
vector<LL> a;
LL ans = 0;
/**********************************************/

int main(){
    cin >> n >> x;
    a.resize(n);
    REP(i, n) cin >> a[i];
    
    REP(i, n-1){
        if(a[i]+a[i+1] > x){
            if(a[i+1] - ((a[i] + a[i+1]) - x) >= 0){
                ans += (a[i] + a[i+1]) - x;
                a[i+1] -= (a[i] + a[i+1]) - x;
            }else{
                ans += a[i+1];
                a[i+1] = 0;
            }
        }
    }

    REPR(i, n-1){
        if(i <= 0) break;
        if(a[i]+a[i-1] > x){
            if(a[i-1] - ((a[i] + a[i-1]) - x) >= 0){
                ans += (a[i] + a[i-1]) - x;
                a[i-1] -= (a[i] + a[i-1]) - x;
            }else{
                ans += a[i-1];
                a[i-1] = 0;
            }
        }
    }

    cout << ans << endl;
}
