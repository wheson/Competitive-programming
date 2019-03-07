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

    string s;
    cin >> s;

    stack<char> st;
    int ans = 0;
    REP(i, s.size()){
        if(s[i] == '0' && !st.empty() && st.top() == '1'){
            ans += 2;
            st.pop();
        }else if(s[i] == '1' && !st.empty() && st.top() == '0'){
            ans += 2;
            st.pop();
        }else{
            st.push(s[i]);
        }
    }
    cout << ans << endl;
}