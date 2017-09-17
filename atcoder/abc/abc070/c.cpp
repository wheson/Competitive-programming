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
//typedef LL int;
typedef pair<int, int> P;
typedef pair<LL, LL> LP;
typedef pair<int, P> PP;
typedef pair<LL, LP> LPP;
int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

int main(){
    int n; 
    LL t[100];
    cin >> n;
    
    LL maxsum = 0;
    REP(i, n){
        cin >> t[i];
        if(maxsum < t[i]){
            maxsum = t[i];
        }
    }
    bool flag = false;
    LL cnt = 1;
    while(1){
        REP(i, n){
            if((maxsum * cnt) % t[i] != 0){
                flag = true;
            }
        }
        if(!flag){
            break;
        }
        cnt++;
        flag = false;
    }
    
    cout << maxsum*cnt << endl;
}
