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
int a, b;
vector<vector<char>> s;
/**********************************************/

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> a >> b;
    a--; b--;
    
    REP(i, 100){
        s.resize(i+1);
        REP(j, 100){
            if(i < 50) s[i].pb('#');
            else s[i].pb('.');
        }
    }
    
    for(int i = 1; i < 49; i += 2){
        for(int j = 0; j < 100; j += 2){
            if(a > 0){
                s[i][j] = '.';
                a--;
            }
        }
    }
    for(int i = 51; i < 99; i += 2){
        for(int j = 0; j < 100; j += 2){
            if(b > 0){
                s[i][j] = '#';
                b--;
            }
        }
    }
    
    cout << 100 << " " << 100 << endl;
    REP(i, 100){
        REP(j, 100) cout << s[i][j];
        cout << endl;
    }

}
