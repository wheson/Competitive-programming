#include <bits/stdc++.h>

using namespace std;
using LL = long long;
using P = pair<int, int>;
using Tapris = tuple<int, int, int>;

#define REP(i, n) for(LL i = 0; i < n; ++i)
#define FOR(i, a, n) for(LL i = a; i < n; ++i)
#define pb(a) push_back(a)
#define all(x) (x).begin(),(x).end()

const int INF = (int)1e9;
const LL INFL = (LL)1e15;
const int MOD = 1e9 + 7;

int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

//#define int long long

/*************** using variables ***************/
string s;
/**********************************************/

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> s;

    int min_range = INF;
    REP(i, s.size()){
        int cnt = 0;
        int max_cnt = 0;
        string ss = s + s[i];
        REP(j, ss.size()){
            if(ss[j] == s[i]){
                max_cnt = max(max_cnt, cnt);
                cnt = 0;
            }else{
                cnt++;
            }
        }
        min_range = min(min_range, max_cnt);
    }
    cout << min_range << endl;

}
