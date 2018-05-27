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
    getline(cin, s);
    REP(i, s.size()){
        if(s[i] == 'L'){
            cout << "<";
            i+=4;
        }
        else if(s[i] == 'R'){
            cout << ">";
            i+=5;
        }
        else if(s[i] == 'A'){
            cout << "A";
            i+=7;
        }
        if(i < s.size()) cout << " ";
    }
    cout << endl;
}
