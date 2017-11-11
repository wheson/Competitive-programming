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
typedef pair<int, int> P;
typedef pair<LL, LL> LP;
typedef pair<int, P> PP;
typedef pair<LL, LP> LPP;
int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

/*************** using variables ***************/
int n;
int t[105], v[105];
int sa[105];
int maxtime = 0;
int currenttime = 0; //ms
double ans = 0;
double speed = 0;
/**********************************************/

int main(){
    cin >> n;
    REP(i, n){
        cin >> t[i];
        maxtime += t[i];
    }
    REP(i, n){
        cin >> v[i];
    }
    
    REP(i, n-1){
        sa[i] = v[i+1] - v[i]; 
    }
    sa[n-1] = -v[n-1];
    
    REP(i, n){
        cout << sa[i] << endl;
    }

    REP(i, n){
        
        currenttime++;
    }
}
