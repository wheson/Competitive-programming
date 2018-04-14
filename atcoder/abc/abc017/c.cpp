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
#include <climits>
#define REP(i, n) for(LL i = 0;i < n;i++)
#define REPR(i, n) for(LL i = n;i >= 0;i--)
#define FOR(i, m, n) for(LL i = m;i < n;i++)
#define FORR(i, m, n) for(LL i = m;i >= n;i--)
#define pb(a) push_back(a)
#define all(x) (x).begin(),(x).end()
#define INF (int)1e9
#define INFL (LL)1e15
#define MOD 1000000007
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

//#define int long long

/*************** using variables ***************/
int n, m;
vector<int> l, r, s;
vector<int> imos;
int ans;
/**********************************************/

signed main(){
    cin >> n >> m;
    l.resize(n);
    r.resize(n);
    s.resize(n);
    imos.resize(m+2);
    REP(i, n) cin >> l[i] >> r[i] >> s[i];
    REP(i, n) ans += s[i];
    REP(i, n){
        imos[l[i]] += s[i];
        imos[r[i]+1] -= s[i];
    }

    for(int i = 1; i < m; i++){
        imos[i+1] = imos[i] + imos[i+1];
    }
    
    int min_num = INF;
    
    for(int i = 1; i <= m; i++){
        min_num = min(min_num, imos[i]);
    }
    ans -= min_num;
    cout << ans << endl;

}
