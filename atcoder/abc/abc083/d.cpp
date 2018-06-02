#include <bits/stdc++.h>
//#define int long long

using namespace std;
using LL = long long;
using P = pair<int, int>;

#define FOR(i, a, n) for(int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)

#define pb(a) push_back(a)
#define all(x) (x).begin(),(x).end()

const int INF = (int)1e9;
const LL INFL = (LL)1e15;
const int MOD = 1e9 + 7;

int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

/*************** using variables **************/
string s;
/**********************************************/

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> s;
    /* ooxoo
       xxooo
       
       xxoxx
       oooxx
       xxoooooxx
       ooxxxxxxx

       xoxxxxxoo
       xoooooooo

       x
    */

    int renzoku = 0, cnt = 1;
    bool flag = s[0] == '1';
    char pre = s[0];
    FOR(i, 1, s.size()){
        if(pre == s[i]){
            cnt++;
        }else if(flag){
            flag = false;
            cnt++;
        }else{
            renzoku = max(renzoku, cnt);
            cnt = 1;
        }
        pre = s[i];
    }
    
    flag = s[s.size()-1] == '1';
    pre = s[s.size()-1];
    cnt = 1;
    for(int i = s.size()-2; i >= 0; i--){
        if(pre == s[i]){
            cnt++;
        }else if(flag){
            flag = false;
            cnt++;
        }else{
            renzoku = max(renzoku, cnt);
            cnt = 1;
        }
        pre = s[i];
    }

    cout << renzoku << endl;
}
