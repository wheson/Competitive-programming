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

int h, w;
vector<string> s;

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    while(1){
        cin >> h >> w;
        if(h == 0 && w == 0) break;
        s.assign(h, "");
        REP(i, h) cin >> s[i];
        map<char, bool> mp;
        REP(i, h){
            REP(j, w){
                if(s[i][j] != '.' && mp[s[i][j]] != true){
                    int wid = 1, hei = 1;
                    for(int x = j+1; x < w; x++) if(s[i][j] == s[i][x]) wid++; else break;
                    for(int y = i+1; y < h; y++) if(s[i][j] == s[y][j]) hei++; else break;
                }
            }
        }
    }
}
