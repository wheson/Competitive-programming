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

/*************** using variables ***************/
LL n, h;
LL a[100005], b[100005];
LL sum_b = 0;
LL max_a = 0;
LL sum = 0;
LL ans = 0;
/**********************************************/

int main(){
    cin >> n;
    cin >> h;
    REP(i, n){
        cin >> a[i] >> b[i];
        max_a = max(max_a, a[i]);
    }
    
    SORT(b, n);
    REPR(i, n-1){
        if(b[i] < max_a) break;
        sum += b[i];
        ans++;
        if(sum >= h ) break;
    }

    if(sum >= h){
        cout << ans << endl;
        return 0;
    }
    while(sum < h){
        sum += max_a;
        ans++;
    }
    cout << ans << endl;
}
