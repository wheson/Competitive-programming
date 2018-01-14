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
int dy[]={0, 0, 1, -1, 1,  1, -1, -1};
int dx[]={1, -1, 0, 0, 1, -1,  1, -1};

/*************** using variables ***************/
int h, w;
string s[55];
/**********************************************/

int main(){
    cin >> h >> w;
    REP(i, h){
        cin >> s[i];
    }

    REP(i, h){
        REP(j, w){
            if(s[i][j] == '.'){
                int num = 0;
                REP(k, 8){
                    int y = dy[k] + i;
                    int x = dx[k] + j;
                    if(y >= 0 && x >= 0 && y < h && x < w){
                        if(s[y][x] == '#') num++;
                    }
                }

                s[i][j] = (char)(num-1 + '1');
            }
        }
    }

    REP(i, h){
        cout << s[i] << endl;
    }
}
