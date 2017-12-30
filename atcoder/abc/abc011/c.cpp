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
int n, ng[3];
int cnt = 0;
/**********************************************/

int main(){
    cin >> n;
    REP(i, 3){
        cin >> ng[i];
    }

    REP(i, 3){
        if(n == ng[i]) {cout << "NO" << endl; return 0;}
    }
    
    while(n != 0 && cnt != 100){
        if(n - 3 != ng[0] && n - 3 != ng[1] && n - 3 != ng[2] && n - 3 >= 0){
            n -= 3;
        }else if(n - 2 != ng[0] && n - 2 != ng[1] && n - 2 != ng[2] && n - 2 >= 0){
            n -= 2;
        }else if(n - 1 != ng[0] && n - 1 != ng[1] && n - 1 != ng[2] && n - 1 >= 0){
            n -= 1;
        }else{
            cout << "NO" << endl;
            return 0;
        }
        cnt++;
    }
    if(n != 0) cout << "NO" << endl;
    else cout << "YES" << endl;
}
