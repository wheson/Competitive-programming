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
int t;
int x = 0, y = 0;
int hatena_cnt = 0;
/**********************************************/

int main(){
    cin >> s >> t;
    if(t == 1){
        REP(i, s.size()){
            if(s[i] == 'L') x -= 1;
            else if(s[i] == 'R') x += 1;
            else if(s[i] == 'U') y += 1;
            else if(s[i] == 'D') y -= 1;
            else{
                hatena_cnt++;
                /*if(max(abs(x-1), abs(x+1)) >= max(abs(y-1), abs(y+1))){
                    if(abs(x-1) >= abs(x+1)){
                        x -= 1;
                    }else{
                        x += 1;
                    }
                }else{
                    if(abs(y-1) >= abs(y+1)){
                        y -= 1;
                    }else{
                        y += 1;
                    }
                }*/
            }
        }
        if(x >= 0){
            REP(i, hatena_cnt) x++;
            
        }else{
            REP(i, hatena_cnt) x--;
        }
    }else{
        REP(i, s.size()){
            if(s[i] == 'L') x -= 1;
            else if(s[i] == 'R') x += 1;
            else if(s[i] == 'U') y += 1;
            else if(s[i] == 'D') y -= 1;
            else{
                hatena_cnt++;
                /*if(min(abs(x-1), abs(x+1)) <= min(abs(y-1), abs(y+1))){
                    if(abs(x-1) < abs(x+1)){
                        x -= 1;
                    }else{
                        x += 1;
                    }
                }else{
                    if(abs(y-1) < abs(y+1)){
                        y -= 1;
                    }else{
                        y += 1;
                    }
                }*/
            }
        }
        REP(i, hatena_cnt){
            if(x > 0) x--;
            else if(x < 0) x++;
            else if(y > 0) y--;
            else if(y < 0) y++;
            else x++;
        }
            
    }
    //cout << x << " " << y << endl;
    cout << abs(x) + abs(y) << endl;
}
