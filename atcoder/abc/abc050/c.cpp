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
vector<int> vec;
/**********************************************/

int main(){
    cin >> n;
    vec.resize(n);

    REP(i, n) cin >> vec[i];

    VSORT(vec);
    if(n % 2 == 0){
        REP(i, n){
            if(vec[i] != 1 + (i / 2) * 2){
                cout << 0 << endl;
                return 0;
            }
        }
    }else{
        if(vec[0] != 0){
            cout << 0 << endl;
            return 0;
        }
        FOR(i, 1, n){
            if(vec[i] != ((i-1) / 2 + 1) * 2){
                cout << 0 << endl;
                return 0;
            }
        } 
    }
    
    int num = n/2;
    LL ans = 1;
    REP(i, num){
        ans = ans * 2 % MOD;
    }
    cout << ans << endl;
}
