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
vector<LL> a, ruiseki1, ruiseki2;

/**********************************************/

int main(){
    cin >> n;
    a.resize(n+5);
    ruiseki1.resize(n+5);
    ruiseki2.resize(n+5);

    REP(i, n) cin >> a[i];
    
    ruiseki1[0] = 0;
    ruiseki2[0] = 0;
    LL cnt1 = 0, cnt2 = 0, sum1 = 0, sum2 = 0;
    REP(i, n){
        ruiseki1[i+1] = ruiseki1[i] + a[i];
        ruiseki2[i+1] = ruiseki2[i] + a[i];
        
        if(i % 2 == 0){
            if(ruiseki1[i+1] >= 0){
                cnt1 += abs(ruiseki1[i+1]) + 1;
                sum1 -= abs(ruiseki1[i+1]) + 1;
                ruiseki1[i+1] = -1;
            }
            if(ruiseki2[i+1] <= 0){
                cnt2 += abs(ruiseki2[i+1]) + 1;
                sum2 += abs(ruiseki2[i+1]) + 1;
                ruiseki2[i+1] = 1;
            }
        }else{
            if(ruiseki1[i+1] <= 0){
                cnt1 += abs(ruiseki1[i+1]) + 1;
                sum1 += abs(ruiseki1[i+1]) + 1;
                ruiseki1[i+1] = 1;
            }
            if(ruiseki2[i+1] >= 0){
                cnt2 += abs(ruiseki2[i+1]) + 1;
                sum2 -= abs(ruiseki2[i+1]) + 1;
                ruiseki2[i+1] = -1;
            }
        }
    }
    cout << min(cnt1, cnt2) << endl;

}
