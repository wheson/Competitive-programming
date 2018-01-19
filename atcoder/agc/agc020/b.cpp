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
int k;
int a[100005];
int current = 500000000;
int maxnum = 1000000000;
int minnum = 2;
/**********************************************/

int nibutan1(int left, int right){
    int mid = (left + right) / 2;
    int num = mid;
    while(left < right){
        mid = (left + right) / 2;
        //cout << left << " " << right << " " << mid << endl;
        REP(i, k){
            num = num - num % a[i];
        }
        if(num < 2) left = mid + 1;
        else right = mid;
    }
    
    num = (left + right) / 2;
    cout << num << endl;
    REP(i, k){
        num = num - num % a[i];
    }

    if(num != 2){
        return -1;
    }
    return (left + right) / 2;
}

int main(){
    cin >> k;
    REP(i, k){
        cin >> a[i];
    }
    
    int ans = nibutan1(minnum, maxnum);
    
    if(ans == -1){
        cout << ans << endl;
        return 0;
    }
    cout << "ans: " << ans << endl;
    int minans = ans - ans % a[0];
    int maxans = minans + (a[0]-1);

    cout << minans << " " << maxans << endl;
}
