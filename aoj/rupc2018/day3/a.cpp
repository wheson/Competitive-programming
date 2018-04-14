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
#include <bitset>
#include <climits>
#define REP(i, n) for(LL i = 0;i < n;i++)
#define REPR(i, n) for(LL i = n;i >= 0;i--)
#define FOR(i, m, n) for(LL i = m;i < n;i++)
#define FORR(i, m, n) for(LL i = m;i >= n;i--)
#define pb(a) push_back(a)
#define all(x) (x).begin(),(x).end()
#define INF (int)1e9
#define INFL (LL)1e15
#define MOD 1000000007
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

//#define int long long

/*************** using variables ***************/
int n;
vector<int> c;
int q;
vector<int> box;
vector<int> t, x, d;
/**********************************************/

signed main(){
    cin >> n;
    c.resize(n);
    box.resize(n);
    REP(i, n) cin >> c[i];
    cin >> q;
    t.resize(q);
    x.resize(q);
    d.resize(q);
REP(i, q){
        cin >> t[i] >> x[i] >> d[i];
}
    REP(i, q){
        if(t[i] == 1 && box[x[i]-1] + d[i] > c[x[i]-1]){
            cout << x[i] << endl;
            return 0;
        }else if(t[i] == 2 && box[x[i]-1] - d[i] < 0){
            cout << x[i] << endl;
            return 0;
        }

        if(t[i] == 1){
            box[x[i]-1] += d[i];
        }else{
            box[x[i]-1] -= d[i];
        }
    }
    cout << "0" << endl;
}
