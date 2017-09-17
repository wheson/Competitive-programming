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
#define REP(i, n) for(int i = 0;i < n;i++)
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

int main(){
    int n;
    vector<int> p;
    cin >> n;
    REP(i, n){
        int x;
        cin >> x;
        p.pb(x);
    }
    // 1 2 3 4 5 6
    int renzoku = 0;
    int cnt = 0;
    REP(i, n){
        if(p[i] == i+1){
            cnt++;
            renzoku++;
            if(renzoku == 2){ cnt--; renzoku = 0;}
        }else{
            renzoku = 0;
        }
    }

    cout << cnt << endl;
}
