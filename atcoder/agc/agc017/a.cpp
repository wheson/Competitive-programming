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
int n, p;
int a[55];
LL ans = 0;
LL even_num = 0, odd_num = 0;
/**********************************************/

LL combination(LL n, LL r){
    LL ret = 1;
    int m = r;
    FORR(i, n, n-r+1){
        ret *= i;
        if(m >= 1 && ret % m == 0){
            ret /= m;
            m--;
        }
    }
    FORR(i, m, 1){
        ret /= i;
    }
    return ret;
}

int main(){
    cin >> n >> p;
    REP(i, n){
        int x;
        cin >> x;
        if(x % 2 == 0){ 
            a[i] = 0;
            even_num++;
        }else{
            a[i] = 1;
            odd_num++;
        }
    }
    
    LL even_cnt; 
    if(even_num != 0) even_cnt = 2;
    else even_cnt = 1;
    FOR(i, 1, even_num){
        even_cnt += combination(even_num, i);
        cout << "even_cnt " << i << ": " << even_cnt << endl;
        cout << "comb(even_num, " << i << "): " << combination(even_num, i) << endl;
    }
    
    if(p == 0){
        LL odd_cnt = 1;
        FOR(i, 2, odd_num){
            if(i % 2 == 0) odd_cnt += combination(odd_num, i);
            cout << "odd_cnt " << i << ": " << odd_cnt << endl;
            cout << "comb(odd_num, " << i << "): " << combination(odd_num, i) << endl;
        }
        cout << even_cnt << " " << odd_cnt << endl;
        ans = even_cnt * odd_cnt;
    }else{
        LL odd_cnt = 0;
        FOR(i, 1, odd_num){
            if(i % 2 == 1) odd_cnt += combination(odd_num, i);
            cout << "odd_num " << i << ": " << odd_cnt << endl;
            cout << "comb(odd_num, " << i << "): " << combination(odd_num, i) << endl;
        }
        ans = even_cnt * odd_cnt;
    }

    cout << ans << endl;
}
