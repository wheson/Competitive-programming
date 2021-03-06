#include <bits/stdc++.h>
#define int long long

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
    map<char, int> mp;
    REP(i, s.size()){
        mp[s[i]]++;
    }

    int sum = 0;
    int sum1 = 0;
    for(auto x : mp){
        sum += x.second - x.second % 2;
        sum1 += x.second % 2;
    }

    cout << (sum + (sum1 == 0 ? 0 : 1)) * (sum + (sum1 == 0 ? 0 : 1)) + max(0LL, sum1 - 1) << endl;
}