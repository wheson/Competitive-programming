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
int min_num = INF;
/**********************************************/

int main(){
    cin >> s;
    
    char pre = s[0];
    int renzoku = 1;
    int soto = 2;
    bool sotof = true;
    FOR(i, 1, s.size()){
        if(pre == s[i]){
            renzoku++;
            if(i == s.size()-1) soto = max(soto, renzoku+1);
        }else if(soto == true && renzoku > 1){
            soto = renzoku+1;
        }else if(renzoku > 1 ){
            min_num = min(min_num, max(renzoku, 2));
            renzoku = 1;
        }else{
            renzoku = 1;
        }
        pre = s[i];
        sotof = false;
    }
    if(min_num == INF) min_num = 2;
    min_num = max(min_num, soto);
    cout << min_num << endl;
}
