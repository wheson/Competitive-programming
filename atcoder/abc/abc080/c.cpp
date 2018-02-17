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
int f[105][15];
int p[105][15];
LL ans = -11410065407;
vector<int> bitcheck;
/**********************************************/

void sol(){
    LL sum = 0;
    for(int i = 0; i < n; i++){
        int cnt = 0;
        for(int j = 0; j < 10; j++){
        //    cout << "i: " << i << " j: " << j << endl;
            if(bitcheck[j] == 1 && f[i][j] == 1){
                cnt++;
            }
        }
        sum += p[i][cnt];
        //cout << "sum: " << sum << endl;
    }
    ans = max(sum, ans);
    return;
}

void dfs(int num){
    if(num == 10){
        sol();
        return;
    }

    if(num == 9){
        REP(i, 10){
            if(bitcheck[i] == 1){
                bitcheck[num] = 0;
                dfs(num+1);
                bitcheck[num] = 1;
                dfs(num+1);
                break;
            }else if(i == 9){
                bitcheck[i] = 1;
                dfs(num+1);
            }
        }
    }else{
        bitcheck[num] = 0;
        dfs(num+1);
        bitcheck[num] = 1;
        dfs(num+1);
    }
}

int main(){
    cin >> n;
    REP(i, n){
        REP(j, 10){
            cin >> f[i][j];
        }
    }

    REP(i, n){
        REP(j, 11){
            cin >> p[i][j];
        }
    }
    bitcheck.resize(15);
    REP(i, 10){
        bitcheck[i] = 0;
    }
    dfs(0);
    cout << ans << endl;
  }
