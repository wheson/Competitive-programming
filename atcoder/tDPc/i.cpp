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
int n;
bool dp[305][305];
LL dp2[305];
/**********************************************/

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> s;
    n = s.size();
    
    // iwiが並んでいるところの区間をtrueにする
    REP(l, n-2){
        int r = l+2;
        if(s.substr(l, 3) == "iwi") dp[l][r] = true;
    }
    
    // dp[l][r]:= lからrまでの区間が全て消せるか否か
    for(int len = 6; len <= n; len += 3){
        REP(l, n){
            int r = l + len - 1;
            if(r >= n) break;
            
            // 2つの消せる区間がある時，その両方をつなげた区間はすべて消せるのでtrue
            // true true
            for(int c = l+3; c < r; c += 3){
                if(dp[l][c-1] && dp[c][r]) dp[l][r] = true;
            }
            
            // 両端に'i', 間に'w'があり，'i'と'w'の間の区間が両方ともtrueの時，iwiが繋がるのでtrue
            // i true w true i
            FOR(c, l+1, r){
                if(s[l] == 'i' && s[c] == 'w' && s[r] == 'i'){
                    if(l + 1 != c && !dp[l+1][c-1]) continue;
                    if(c + 1 != r && !dp[c+1][r-1]) continue;
                    dp[l][r] = true;
                }
            }
        }
    } 
    // dp2[n]:= 区間[0, n]で消せる数の総和
    FOR(r, 1, n){
        dp2[r] = dp2[r-1];
        REP(l, r){
            if(dp[l][r]){
                if(l == 0) dp2[r] = max(dp2[r], (r - l + 1) / 3);
                else dp2[r] = max(dp2[r], dp2[l-1] + (r - l + 1)/ 3);
            }
        }
    }
    cout << dp2[n-1] << endl;
}
