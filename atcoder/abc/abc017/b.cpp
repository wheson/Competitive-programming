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
string x;
/**********************************************/

int main(){
    cin >> x;
    if(x == ""){
        cout << "YES" << endl;
    }

    while(x.size() != 0){
        if(x.substr(0, 2) == "ch"){
            x.erase(x.begin(), x.begin()+2);
        }else if(x.substr(0, 1) == "o" || x.substr(0, 1) == "k" || x.substr(0, 1) == "u"){
            x.erase(x.begin(), x.begin()+1);
        }else{
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}
