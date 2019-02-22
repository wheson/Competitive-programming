#include <bits/stdc++.h>
//#define int long long

using namespace std;
using LL = long long;

#define FOR(i, a, n) for(int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)

#define pb(a) push_back(a)
#define all(x) (x).begin(),(x).end()

const int INF = (int)1e9;
const LL INFL = (LL)1e19;
const int MOD = (int)1e9 + 7;

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    FOR(i, 1, n+1){
        string ans = "";
        if(i % 2 == 0){
            ans = ans + 'a';
        }
        if(i % 3 == 0){
            ans = ans + 'b';
        }
        if(i % 4 == 0){
            ans = ans + 'c';
        }
        if(i % 5 == 0){
            ans = ans + 'd';
        }
        if(i % 6 == 0){
            ans = ans + 'e';
        }
        cout << (ans == "" ? to_string(i) : ans) << endl;
    }
}