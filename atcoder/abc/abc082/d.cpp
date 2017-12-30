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
string s;
int ssize = 0;
int x, y;
vector<int> vec_jouge, vec_sayuu;
bool ans = false;
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
/**********************************************/

bool xdfs(int i, int current_x){
    //cout << "x i: " << i << "x: " << vec_sayuu[i] << endl;
    
    if(vec_sayuu.size() == i){
        if(current_x == x){
            return true;
        }else{
            return false;
        }
    }

    return xdfs(i+1, current_x + vec_sayuu[i]) || xdfs(i+1, current_x - vec_sayuu[i]);
}

bool ydfs(int i, int current_y){
    //cout << "y i: " << i << "y: " << vec_jouge[i] << endl;
    if(vec_jouge.size() == i){
        if(current_y == y){
            return true;
        }else{
            return false;
        }
    }

    return ydfs(i+1, current_y + vec_jouge[i]) || ydfs(i+1, current_y - vec_jouge[i]);
}

int main(){
    cin >> s;
    cin >> x >> y;
    ssize = s.size();
    
    int dir = 1;
    REP(i, ssize){
        int fnum = 0;
        if(s[i] == 'F'){
            while(i < ssize && s[i] == 'F'){
                fnum++; i++;
            }
            
            if(dir == -1){
                vec_jouge.pb(fnum);
            }else{
                vec_sayuu.pb(fnum);
            }
        }else{
        
        }
        dir *= -1;
    }

    VSORT(vec_jouge); VSORT(vec_sayuu);

   ans = xdfs(0, 0) && ydfs(0, 0); 

    if(ans){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}
