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
typedef pair<int, int> P;
typedef pair<LL, LL> LP;
typedef pair<int, P> PP;
typedef pair<LL, LP> LPP;
int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

/*************** using variables ***************/
string s, t;
int ssize, tsize;
int irekaeP;
/**********************************************/

int search(){
    FORR(i, ssize - 1, tsize - 1){
        int cnt = 0;
        FORR(j, tsize - 1, 0){
            if(s[i - cnt] != t[j] && s[i - cnt] != '?'){
                break;
            } 
            if(j == 0){
                return i-tsize+1;
            }
            cnt++;
        }
    }
    return -1;
}

int main(){
    cin >> s >> t;
    ssize = s.size();
    tsize = t.size();
    
    irekaeP = search();
    if(irekaeP != -1){
        s.replace(irekaeP, tsize, t);
        REP(i, ssize){
            if(s[i] == '?') s[i] = 'a';
        }
        cout << s << endl;
    }else{
        cout << "UNRESTORABLE" << endl;
    }
}
