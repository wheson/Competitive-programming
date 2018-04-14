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
#include <limits.h>
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
int n;
LL ans = 0;
map<char, LL> mp;
/**********************************************/

signed main(){
    cin >> n;
    mp['M'] = 0;
    mp['A'] = 0;
    mp['R'] = 0;
    mp['C'] = 0;
    mp['H'] = 0;
    REP(i, n){
        string s;
        cin >> s;
        mp[s[0]]++;
    }
    
    ans += mp['M'] * mp['A'] * mp['R'];
    ans += mp['M'] * mp['A'] * mp['C'];
    ans += mp['M'] * mp['A'] * mp['H'];
    ans += mp['M'] * mp['R'] * mp['C'];
    ans += mp['M'] * mp['R'] * mp['H'];
    ans += mp['M'] * mp['C'] * mp['H'];
    ans += mp['A'] * mp['R'] * mp['C'];
    ans += mp['A'] * mp['R'] * mp['H'];
    ans += mp['A'] * mp['C'] * mp['H'];
    ans += mp['R'] * mp['C'] * mp['H'];
    cout << ans << endl;
}
