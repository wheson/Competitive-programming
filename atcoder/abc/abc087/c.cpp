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
int a[2][105];
int ruisekiwa[2][105];
int ans = 0;
/**********************************************/

int main(){
    cin >> n;
    REP(i, n) cin >> a[0][i];
    REP(i, n) cin >> a[1][i];
    
    ruisekiwa[0][0] = 0;
    ruisekiwa[1][0] = 0;
    FOR(i, 1, n+1){
        ruisekiwa[0][i] = ruisekiwa[0][i-1] + a[0][i-1]; 
        ruisekiwa[1][i] = ruisekiwa[1][i-1] + a[1][i-1]; 
    }
    REP(i, n){
        ans = max(ruisekiwa[0][i+1] + ruisekiwa[1][n] - ruisekiwa[1][i], ans);
    }

    cout << ans << endl;
}
