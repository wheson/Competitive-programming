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
    const string org = s;
    
    for(int len = (int)org.size(); len >= 0; len--){
        string f = org;
        sort(all(f));
        
        map<char, int> mp1, mp2;
        for(int i = len; i < (int)org.size(); i++){
            mp1[org[i]]++; mp2[f[i]]++;
        }
        int cnt = 0;
        REP(i, len) if(org[i] != f[i]) cnt++;
        int nnn = 0;
        for(char c = 'a'; c <= 'z'; c++){
            nnn += abs(mp1[c] - mp2[c]);
        }
        cnt += nnn/2;
        if(cnt <= k){
            REP(i, org.size()){
                if(i < len) cout << f[i];
                else if(mp2[org[i]] >= 1){
                    cout << org[i];
                    mp2[org[i]]--;
                    mp1[org[i]]--;
                }else{
                    for(char c = 'a'; c <= 'z'; c++){
                        if(mp2[c] - mp1[c] >= 1){
                            cout << c;
                            mp2[c]--;
                            break;
                        }
                    }
                }
            }
            cout << endl;
            return 0;
        }
    }
}
