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
int n, y;
int ans_1000 = -1, ans_5000 = -1, ans_10000 = -1; 
/**********************************************/

int main(){
    cin >> n >> y;
    REP(i, n+1){
        REP(j, n+1){
           if(n-i-j >= 0 && i*10000 + j*5000 + (n-i-j)*1000 == y){
               cout << i << " " << j << " " << n-i-j << endl;
               return 0;
           }   
        }
    }
    cout << ans_10000 << " " << ans_5000 << " " << ans_1000 << endl; 
}
