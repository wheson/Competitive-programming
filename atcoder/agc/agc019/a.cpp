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
//typedef LL int;
typedef pair<int, int> P;
typedef pair<LL, LL> LP;
typedef pair<int, P> PP;
typedef pair<LL, LP> LPP;
int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

int main(){
    int q, h, s, d;
    int n;

    cin >> q >> h >> s >> d >> n;
    int tiisai = min(min(q*4, h*2), s);
    bool flag = false;
    if(tiisai*2 < d) flag = true;
    
    LL ans = 0;
    while(1){
        if(n == 0) break;
        if(!flag && n-2 >= 0){
            ans += d;
            n -= 2;
        }else{
            ans += tiisai;
            n -= 1;
        }
    }

    cout << ans << endl;
}
