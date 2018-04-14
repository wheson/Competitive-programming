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
#include <limits.h>
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

#define int long long

/*************** using variables ***************/
int R, C, K, N;
vector<int> r, c;
vector<int> x, y, xx, yy;
int sum = 0;
int ans = 0;
/**********************************************/

signed main(){
    cin >> R >> C >> K >> N;
    r.resize(N);
    c.resize(N);
    x.resize(C+1, 0);
    y.resize(R+1, 0);
    xx.resize(N+1, 0);
    yy.resize(N+1, 0);
    REP(i, N) cin >> r[i] >> c[i];
    REP(i, N){
        y[r[i]]++;
        x[c[i]]++; 
    }
    
    FOR(i, 1, R+1){
        yy[y[i]]++;
    }

    FOR(i, 1, C+1){
        xx[x[i]]++;
    }

    FOR(i, 0, K+1){
        ans += xx[i] * yy[K-i];
    }

    REP(i, N){
        if(y[r[i]] + x[c[i]] == K) ans--;
        if(y[r[i]] + x[c[i]] == K + 1) ans++;
    }
    cout << ans << endl;
}
