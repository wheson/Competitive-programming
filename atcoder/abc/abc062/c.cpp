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
int h, w;
LL max1 = 0, max2 = 0, min1 = INF, min2 = INF;
LL ans1 = INF, ans2 = INF; 
/**********************************************/

int main(){
    cin >> h >> w;
    if(h%3 == 0 || w%3 == 0){
        cout << 0 << endl;
        return 0;
    }
    
    FOR(i, 1, w){
        LL ax = i, ay = h, bx = w-ax, by = h/2, cx = w-ax, cy = h-by;
        if(ax > 0 && ay > 0 && bx > 0 && by > 0 && cx > 0 && cy > 0){
            max1 = max(max(ax * ay, bx * by), cx * cy);
            min1 = min(min(ax * ay, bx * by), cx * cy);
            ans1 = min(max1 - min1, ans1);
        } 
        ax = i, ay = h, bx = (w-ax)/2, by = h, cx = w-ax-bx, cy = h;
        if(ax > 0 && ay > 0 && bx > 0 && by > 0 && cx > 0 && cy > 0){
            max1 = max(max(ax * ay, bx * by), cx * cy);
            min1 = min(min(ax * ay, bx * by), cx * cy);
            ans1 = min(max1 - min1, ans1);
        }
    }
    
    FOR(i, 1, h){
        LL ax = w, ay = i, bx = w/2, by = h-ay, cx = w-bx, cy = h-ay;
        if(ax > 0 && ay > 0 && bx > 0 && by > 0 && cx > 0 && cy > 0){
            max1 = max(max(ax * ay, bx * by), cx * cy);
            min1 = min(min(ax * ay, bx * by), cx * cy);
            ans1 = min(max1 - min1, ans1);
        } 
        ax = w, ay = i, bx = w, by = (h-ay)/2, cx = w, cy = h-ay-by;
        if(ax > 0 && ay > 0 && bx > 0 && by > 0 && cx > 0 && cy > 0){
            max1 = max(max(ax * ay, bx * by), cx * cy);
            min1 = min(min(ax * ay, bx * by), cx * cy);
            ans1 = min(max1 - min1, ans1);
        }
    }
    
    cout << min(ans1, ans2) << endl;
}
