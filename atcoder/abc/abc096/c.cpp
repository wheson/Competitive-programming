#include <bits/stdc++.h>
//#define int long long

using namespace std;
using LL = long long;
using P = pair<int, int>;
using Tapris = tuple<int, int, int>;

#define FOR(i, a, n) for(int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)

#define pb(a) push_back(a)
#define all(x) (x).begin(),(x).end()

const int INF = (int)1e9;
const LL INFL = (LL)1e15;
const int MOD = 1e9 + 7;

int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

/*************** using variables ***************/
int h, w;
vector<string> s;
/**********************************************/

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> h >> w;
    s.resize(h);
    REP(i, h) cin >> s[i];

    REP(i, h)REP(j, w) if(s[i][j] == '#'){
        bool flag = false;
        if(i-1 >= 0) flag |= s[i-1][j] == '#';
        if(i+1 < h) flag |= s[i+1][j] == '#';
        if(j-1 >= 0) flag |= s[i][j-1] == '#';
        if(j+1 < w) flag |= s[i][j+1] == '#';

        if(!flag){
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
}
