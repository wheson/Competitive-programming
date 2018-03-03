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

#define int long long

/*************** using variables ***************/
int n, k;
vector<int> s;
LL mul = 1;
int ans = 0;
int r = 0, l = 0;
/**********************************************/

signed main(){
    cin >> n >> k;
    s.resize(n);
    REP(i, n){
        cin >> s[i];
    }
    REP(i, n){
        if(s[i] == 0){
            cout << n << endl;
            return 0;
        }
    }
    
    while(1){
        if(r >= n) break;
        while(1){
            if(r >= n || mul * s[r] > k) break;
            else{
                mul *= s[r];
                r++;
            }
        } 
        ans = max(ans, r-l);
        if(l == r){
            break;
        }else{
            mul /= s[l];
            l++;
        }
    }

    cout << ans << endl;
}
