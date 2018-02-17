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

//#define int long long

/*************** using variables ***************/
string s;
LL ans = 0;
/**********************************************/

int ctoi(char c){
    return (int)(c - '0');
}

void dfs(LL i, string str_input){
    string str = str_input;
    if(i == s.size()){
        LL sum = 0;
        LL num = 0;
        REP(j, str.size()){
            if(str[j] == '+'){
                sum += num;
                num = 0;
            }else if(str[j] != '+'){
                num *= 10;
                num += ctoi(str[j]);
            }
        }
        sum += num;
        ans += sum;
        return;
    }
    str = str + s[i];
    dfs(i+1, str);
    if(i < s.size()-1){
        str = str + "+";
        dfs(i+1, str);
    }
    return;
}

signed main(){
    cin >> s;
    
    dfs(0, "");

    cout << ans << endl;
}
