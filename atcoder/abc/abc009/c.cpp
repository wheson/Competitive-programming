#include <bits/stdc++.h>
//#define int long long

using namespace std;
using LL = long long;
using P = pair<int, int>;
using Tapris = tuple<int, int, int>;

#define FOR(i, a, n) for(int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)

#define pb(a) push_back(a)
#define all(x) (x).begin(),(x).end()

const int INF = (int)1e9;
const LL INFL = (LL)1e15;
const int MOD = 1e9 + 7;

int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

/*************** using variables ***************/
int n, k;
string s;
/**********************************************/

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n >> k >> s;
    string ans = "";
    map<char, int> mp;
    REP(i, n) mp[s[i]]++;

    REP(i, n){
        for(char c = 'a'; c <= 'z'; c++){
            if(mp[c] == 0) continue;
            if(s[i] == c){
                mp[c]--; ans += c; break;
            }
            mp[c]--;
            k--;
            bool flag = true;
            int cnt = 0;
            int d[26] = {};
            FOR(j, i+1, n) d[s[j] - 'a']++;
            REP(j, 26) cnt += min(d[j], mp['a'+j]);
            if(n - 1 - i - cnt > k) flag = false;
            if(flag) {ans += c; break;}
            mp[c]++;
            k++;
        }
    }
    cout << ans << endl;
}
