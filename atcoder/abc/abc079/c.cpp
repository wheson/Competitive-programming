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
int a, b, c, d;
/**********************************************/

int main(){
    cin >> s;
    a = s[0] - '0';
    b = s[1] - '0';
    c = s[2] - '0';
    d = s[3] - '0';
    
    if(a+b+c+d == 7){
        cout << a << '+' << b << '+' << c << '+' << d << '=' << 7 << endl;   
    }else if(a+b-c+d == 7){
        cout << a << '+' << b << '-' << c << '+' << d << '=' << 7 << endl;   
    }else if(a+b-c-d == 7){
        cout << a << '+' << b << '-' << c << '-' << d << '=' << 7 << endl;   
    }else if(a+b+c-d == 7){
        cout << a << '+' << b << '+' << c << '-' << d << '=' << 7 << endl;   
    }else if(a-b+c+d == 7){
        cout << a << '-' << b << '+' << c << '+' << d << '=' << 7 << endl;   
    }else if(a-b-c+d == 7){
        cout << a << '-' << b << '-' << c << '+' << d << '=' << 7 << endl;   
    }else if(a-b-c-d == 7){
        cout << a << '-' << b << '-' << c << '-' << d << '=' << 7 << endl;   
    }else if(a-b+c-d == 7){
        cout << a << '-' << b << '+' << c << '-' << d << '=' << 7 << endl;   
    }
}
