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

/*************** using variables ***************/
int n;
vector<int> a, b, c;
LL ans = 0;
/**********************************************/

int main(){
    cin >> n;

    REP(i, n){
        int x;
        cin >> x;
        a.pb(x);
    }
    REP(i, n){
        int x;
        cin >> x;
        b.pb(x);
    }

    REP(i, n){
        int x;
        cin >> x;
        c.pb(x);
    }
    VSORT(a);
    VSORT(c);
    
    REP(i, n){
        vector<int>::iterator it = lower_bound(all(a), b[i]);
        //
        LL ab = LL(it - a.begin());
        //cout << "ab: " << ab << endl;
        it = upper_bound(all(c), b[i]);
        LL bc = n - LL(it - c.begin());
        //cout << "bc: " << bc << endl;
        ans += ab * bc;
    }
    
    cout << ans << endl;
    
}
