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

/*************** using variables ***************/
int n;
vector<int> b;
vector<int> max_s, min_s, s;
/**********************************************/

signed main(){
    cin >> n;
    b.resize(n-1);
    REP(i, n-1) cin >> b[i];
    
    max_s.resize(n+1);
    min_s.resize(n+1);
    s.resize(n+1);
    
    REP(i, n+1){
        max_s[i] = 0; min_s[i] = (int)1e9;
    }

    for(int i = n-2; i >= 0; i--){
        if(max_s[i+2] == 0) s[i+2] = 1;
        else s[i+2] = max_s[i+2] + min_s[i+2] + 1;
        max_s[b[i]] = max(s[i+2], max_s[b[i]]);
        min_s[b[i]] = min(s[i+2], min_s[b[i]]);
    }
    s[1] = max_s[1] + min_s[1] + 1;
    cout << s[1] << endl;
}
