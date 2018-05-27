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

/*************** using variables **************/
string s;
int k;
set<string> st;
/**********************************************/

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> s >> k;
    
    for(char c = 'a'; c <= 'z'; c++){
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'c'){
                for(int j = 1; j <= k && i+j <= s.size(); j++){
                    st.insert(s.substr(i, j));
                }
            }
        }
        if(st.size() >= k) break;
    }
    auto itr = st.begin();
    REP(i, k-1){
        ++itr;
    }
    cout << *itr << endl;
}
