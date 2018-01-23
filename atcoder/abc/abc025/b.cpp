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
int n, a, b;
string s[105];
int d[105];
/**********************************************/

int main(){
    cin >> n >> a >> b;
    REP(i, n) cin >> s[i] >> d[i];

    int coordinates = 0;
    REP(i, n){
        if(d[i] < a){
            if(s[i] == "West"){
                coordinates -= a;
            }else{
                coordinates += a;
            }
        }else if(d[i] <= b){
            if(s[i] == "West"){
                coordinates -= d[i];
            }else{
                coordinates += d[i];
            }
        }else{
            if(s[i] == "West"){
                coordinates -= b;
            }else{
                coordinates += b;
            }
        }
    }

    if(coordinates < 0){
        cout << "West" << " " << abs(coordinates) << endl;
    }else if(coordinates > 0){
        cout << "East" << " " << coordinates << endl;
    }else{
        cout << 0 << endl;
    }
}
