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
int n, m;
int a[55], b[55], c[55], d[55];
/**********************************************/

int main(){
    cin >> n >> m;
    REP(i, n){
        cin >> a[i] >> b[i];
    }
    REP(i, m){
        cin >> c[i] >> d[i];
    }

    REP(i, n){
        int point = 0; 
        REP(j, m){
           if(abs(a[i]-c[j])+abs(b[i]-d[j]) < abs(a[i]-c[point])+abs(b[i]-d[point])){
               point = j;
           } 
        }
        cout << point+1 << endl;
    }
}
