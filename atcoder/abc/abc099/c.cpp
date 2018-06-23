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

int n;
int ans = 0;

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n;
    set<int> st;
    for(int i = 0; pow(9, i) <= 100000; i++) st.insert(pow(9, i));
    for(int i = 0; pow(6, i) <= 100000; i++) st.insert(pow(6, i));
    vector<int> vec;
    for(auto x: st) vec.pb(x);
    sort(all(vec), greater<int>());
    
    vector<int> dp(100500, INF);
    dp[0] = 0;
    for(int i = 0; i < vec.size(); i++){
        for(int j = vec[i]; j <= 100000; j++){
            dp[j] = min(dp[j], dp[j-vec[i]]+1);
        }
    }
    cout << dp[n] << endl;
    
}
