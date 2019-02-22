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
const LL INFL = (LL)1e18;
const int MOD = (int)1e9 + 7;

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;

    if(s[0] == s[s.size()-1]){
        if(s.size() % 2 == 0){
            cout << "First" << endl;
        }else{
            cout << "Second" << endl;
        }
    }else{
        if(s.size() % 2 == 0){
            cout << "Second" << endl;
        }else{
            cout << "First" << endl;
        }
    }
}