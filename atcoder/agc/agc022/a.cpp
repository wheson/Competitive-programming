#include <bits/stdc++.h>

using namespace std;
using LL = long long;
using P = pair<int, int>;
using Tapris = tuple<int, int, int>;

#define rep(i, n) for(LL i = 0;i < n;i++)
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
map<char, bool> mp;
/**********************************************/

signed main(){
    cin >> s;
    rep(i, s.size()){
        mp[s[i]] = true;
    }
    int ssize = s.size();
    char ans;
    bool flag = false;
    for(; ssize >= 0; ssize--){
        flag = false;
        rep(i, 26){
            if(mp[(char)(i+'a')] == false && (char)(i+'a') > s[ssize]){
                ans = (char)(i+'a');
                flag = true;
                break;
            }
        }
        if(!flag){
            mp[s[ssize]] = false;
        }else{
            break;
        }
    }
    if(flag == false){
        cout << -1 << endl;
    }else{
        rep(i, ssize){
            cout << s[i];
        }
        cout << ans << endl;
    }
}
