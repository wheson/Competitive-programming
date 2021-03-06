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
vector<LL> a;
map<LL, LL> b;
/**********************************************/

int main(){
    cin >> n;
    a.resize(n+5);
    REP(i, n) cin >> a[i];
        sort(a.begin(), a.end(), std::greater<LL>());
    
    LL pre = -1;
    LL tmp = -1;
    int cnt = 0;
    REP(i, n){
        if(cnt == 1 && pre == a[i]){
            LL ans = tmp * a[i];
            cout << ans << endl;
            return 0;
        }else if(cnt == 0 && pre == a[i]){
            tmp = a[i];
            pre = -1;
            cnt++;
        }else{
            pre = a[i];
        }
    }

    cout << 0 << endl;
}
