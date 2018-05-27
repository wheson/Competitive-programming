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
    if(s.size() == 2){
        if(s[0] == s[1]) cout << 1 << " " << 2 << endl;
        else cout << -1 << " " << -1 << endl;
        return 0;
    }
    FOR(i, 2, s.size()){
        if(s[i] == s[i-1]){
            cout << i-1 + 1 << " " << i+1 << endl;
            return 0;
        }else if(s[i] == s[i-2]){
            cout << i-2 + 1 << " " << i+1 << endl;
            return 0;
        }
    }
    cout << -1 << " " << -1 << endl;
}
