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
string s;
/**********************************************/

int main(){
    cin >> s;
    char ch[2] = {'2', '5'};
    int current = 0;
    int ans = 0;
    while(1){
        current = 0;
        bool flag = true;
        REP(i, s.size()){
            if(s[i] != '0') flag = false;
        }
        if(flag) break;

        flag = true;
        REP(i, s.size()){
            if(s[i] == ch[current]){
                s[i] = '0';
                current = (current+1) % 2;
                flag = false;
            }
        }
        if(flag || ch[current] == '5'){
            cout << -1 << endl;
            return 0;
        }
        ans++;
    }

    cout << ans << endl;
} 
