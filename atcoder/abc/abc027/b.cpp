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
int a[105];
int ruiseki[105];
/**********************************************/

int main(){
    cin >> n;
    REP(i, n) cin >> a[i];
    ruiseki[0] = 0;
    FOR(i, 1, n+1){
        ruiseki[i] = ruiseki[i-1] + a[i-1];
    }
    /*REP(i, n+1){
        cout << ruiseki[i] << endl;
    }*/
    int ave = ruiseki[n] / n;
    if(ruiseki[n] % n != 0){
        cout << -1 << endl;
        return 0;
    }
    if(ave == 0){
        cout << 0 << endl;
        return 0;
    }

    int ans = 0;
    int start_p = 0;
    int cnt = 1;
    
    REP(i, n){
        //cout << ruiseki[start_p + cnt] - ruiseki[start_p] << " == " << ave * cnt << endl;
        if((ruiseki[start_p + cnt] - ruiseki[start_p]) == ave * cnt){
            ans += cnt - 1;
            start_p = i+1;
            cnt = 1;
        }else{
            cnt++;
        }
    }
    cout << ans << endl;
}
