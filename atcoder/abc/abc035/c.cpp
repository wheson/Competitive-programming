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

//#define int long long

/*************** using variables ***************/
int n, q;
vector<int> l, r, base, ans;
/**********************************************/

signed main(){
    cin >> n >> q;
    l.resize(q+5); r.resize(q+5); base.resize(n+5), ans.resize(n+5);
    REP(i, q) cin >> l[i] >> r[i];

    REP(i, n){
        base[i] = 0; ans[i] = 0;
    }
    
    REP(i, q){
        base[l[i]-1]++;
        base[r[i]]--;
    }
    
    ans[0] = base[0];
    FOR(i, 1, n){
        ans[i] = ans[i-1] + base[i];
    }

    REP(i, n){
        //cout << base[i];
        cout << ans[i]%2;
    }
    cout << endl;
}
