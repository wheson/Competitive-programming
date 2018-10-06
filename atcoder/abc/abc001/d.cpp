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
const int MOD = 1e9 + 7;

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<string> s(n);
    REP(i, n) cin >> s[i];

    vector<int> imos(2450, 0);
    REP(i, n){
        int a = stoi(s[i].substr(0, 4));
        int b = stoi(s[i].substr(5, 4));
        a -= a % 5;
        b += (b % 5 != 0 ? 5 - b % 5 : 0);
        
        if(a % 100 == 60) a += 100, a -= a % 100;
        if(b % 100 == 60) b += 100, b -= b % 100;
        imos[a]++; imos[b]--;
    }
    REP(i, 2405){
        imos[i+1] += imos[i];
    }
    
    bool flag = false;
    REP(i, 2405){
        if(!flag && imos[i]){
            cout << setfill('0') << setw(4) << right << i << '-';
            flag = true;
        }else if(flag && imos[i] <= 0){
            cout << setfill('0') << setw(4) << right << i << endl;
            flag = false;
        }
    }
    
}
