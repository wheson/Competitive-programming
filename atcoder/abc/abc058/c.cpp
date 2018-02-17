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
#define INF (int)1e15
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
int n;
vector<string> s;
vector<map<char, int>> mp;
/**********************************************/

int main(){
    cin >> n;
    s.resize(n+5);
    mp.resize(n+5);
    REP(i, n) cin >> s[i];

    REP(i, n){
        REP(j, s[i].size()){
            mp[i][s[i][j]]++;
        }
    }

    for(int i = 0; 'a'+ i != 'z' + 1; i++){
        int num = INF;
        REP(j, n){
            num = min(mp[j][(char)('a'+i)], num);
        }
        REP(j, num){
            cout << (char)('a'+i);
        }
    }
    cout << endl;
}
