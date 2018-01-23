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
string s;
/**********************************************/

int main(){
    cin >> s;
    string ans = "";
    char pre = s[0];
    int cnt = 1;
    FOR(i, 1, s.size()){
        if(pre == s[i]){
            cnt++;
            if(i == s.size()-1){
                ans = ans + pre + to_string(cnt);
            }
        }else{
            ans = ans + pre + to_string(cnt);
            cnt = 1;
            pre = s[i];
            if(i == s.size()-1){
                ans = ans + s[i] + to_string(cnt);
            }
        }
    }

    cout << ans << endl;
}
