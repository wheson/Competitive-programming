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

    string s;
    cin >> s;

    int n = s.size();
    string key = "keyence";
    int index = 0;
    REP(i, n){
        if(s[i] != key[index]) break;
        index++;
        if(index == 7) break;
    }
    int num = index;
    REP(i, 7 - num){
        if(s[n - (7 - num) + i] != key[index]) break;
        index++;
        if(index == 7) break;
    }

    if(index == 7) cout << "YES" << endl;
    else cout << "NO" << endl;

}