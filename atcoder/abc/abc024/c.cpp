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

//#define int long long

/*************** using variables ***************/
int n, d, k;
vector<int> l, r, s, t;
/**********************************************/

signed main(){
    cin >> n >> d >> k;
    l.resize(d);
    r.resize(d);
    s.resize(k);
    t.resize(k);
    REP(i, d) cin >> l[i] >> r[i];
    REP(i, k) cin >> s[i] >> t[i];

    REP(i, k){
        int day = 0;
        int now_p = s[i];
        if(s[i] < t[i]){
            REP(j, d){
                day++;
                if(now_p >= l[j] && now_p <= r[j]){
                    if(t[i] >= l[j] && t[i] <= r[j]) break;
                    now_p = r[j];
                }
            }
        }else{
            REP(j, d){
                day++;
                if(now_p >= l[j] && now_p <= r[j]){
                    if(t[i] >= l[j] && t[i] <= r[j]) break;
                    now_p = l[j];
                }
            }
        }
        cout << day << endl;
    }
}
