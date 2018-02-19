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
#define INF (int)1e8
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
int c[3][3];
int a[3], b[3];
/**********************************************/

signed main(){
    REP(i, 3){
        REP(j, 3){
            cin >> c[i][j];
        }
    }
    
    a[0] = 0;
    REP(i, 3){
        b[i] = c[0][i] - a[0];
    }
    FOR(i, 1, 3){
        a[i] = c[i][0] - b[0];
    }

    REP(i, 3){
        REP(j, 3){
            if(a[i] + b[j] != c[i][j]){
                cout << "No" << endl;
                return 0;
            }
        }
    }

    cout << "Yes"  << endl;
}
