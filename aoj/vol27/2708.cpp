#include <bits/stdc++.h>

using namespace std;
using LL = long long;
using P = pair<int, int>;
using Tapris = tuple<int, int, int>;

#define int long long
#define REP(i, n) for(LL i = 0; i < n; ++i)
#define FOR(i, a, n) for(LL i = a; i < n; ++i)
#define pb(a) push_back(a)
#define all(x) (x).begin(),(x).end()

const int INF = (int)1e9;
const LL INFL = (LL)1e15;
const int MOD = 1e9 + 7;

int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};


bool dfs(string s){
    if(s == "ABC") return true;
    else if(s.find("ABC") == string::npos) return false;
    vector<bool> valid(3, true);
    
    string t;
    int i = 0;
    while(i < s.size()){
        if(i <= (int)s.size() - 3 && s.substr(i, 3) == "ABC"){
            i += 3;
        }else{
            t += s[i];
            i++;
        }
    }
    REP(i, t.size()) valid[t[i] - 'A'] = false;
    
    bool ret = false;
    REP(k, 3){
        if(!valid[k]) continue;
        string t;
        int i = 0;
        while(i < s.size()){
            if(i <= (int)s.size() - 3 && s.substr(i, 3) == "ABC"){
                t += 'A' + k;
                i += 3;
            }else{
                t += s[i];
                i++;
            }
        }
        ret |= dfs(t);
    }
     
    return ret;
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    string s; 
    cin >> s;
    cout << (dfs(s) ? "Yes":"No") << endl; 
}
