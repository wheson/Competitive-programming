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
const LL INFL = (LL)1e19;
const int MOD = 1e9 + 7;

signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n, a;
    cin >> n >> a;
    string k;
    cin >> k;
    vector<int> b(n);
    REP(i, n) cin >> b[i];

    map<int, int> next;
    REP(i, n) next[i+1] = b[i];

    vector<int> re;
    re.push_back(a);
    int cur = a;
    vector<bool> closed(n+1);
    while(1){
        re.push_back(next[cur]);
        if(closed[next[cur]]) break;
        closed[next[cur]] = true;
        cur = next[cur];
    }

    int index = -1;
    REP(i, re.size()) if(re.back() == re[i]){ index = i+1; break; }
    int mod = re.size() - index;

    int c = 0;
    REP(i, k.size()){
        c = (c * 10 + (int)(k[i] + '0')) % mod;
    }

    if(to_string(index).size() >= k.size() && index > atoi(k.data())){
        cout << re[atoi(k.data())] << endl;
    }else{
        c = (c + mod - index) % mod;
        cout << re[c+index] << endl;
    }
}