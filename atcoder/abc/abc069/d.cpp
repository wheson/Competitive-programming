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
    int h,w,n;
    cin >> h >> w >> n;

    int a[10000];
    REP(i, n){
        cin >> a[i];
    }
    
    deque<int> dq;
    REP(i, n){
        REP(j, a[i]){
            dq.pb(i+1);
        }
    }

    deque<int> ans[100];

    REP(i, h){
        REP(j, w){
            if(i % 2 == 0){
                int x;
                x = dq.front(); dq.pop_front();
                ans[i].push_back(x);
            }else{
                int x;
                x = dq.front(); dq.pop_front();
                ans[i].push_front(x);
            }
        }
    }

    REP(i, h){
        REP(j, w){
            int x;
            x = ans[i].front(); ans[i].pop_front();
            cout << x << " "; 
        }
        cout << endl;
    }
}
