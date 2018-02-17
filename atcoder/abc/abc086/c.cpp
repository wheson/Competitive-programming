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
int t[100005], x[100005], y[100005];
/**********************************************/

int main(){
    cin >> n;
    REP(i, n) cin >> t[i] >> x[i] >> y[i];
    
    int cur_x = 0, cur_y = 0, cur_t = 0;
    REP(i, n){
        int diff_x = abs(x[i] - cur_x);
        int diff_y = abs(y[i] - cur_y);
        int sum = diff_x + diff_y;
        int diff_t = t[i] - cur_t;
        if(t[i] - cur_t < sum){
            cout << "No" << endl;
            return 0;
        }else if((diff_t + sum % 2) % 2 != 0){
            cout << "No" << endl;
            return 0;
        }

        cur_x = x[i]; cur_y = y[i]; cur_t = t[i];
    }
    cout << "Yes" << endl;
}
