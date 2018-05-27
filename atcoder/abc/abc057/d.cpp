#include <bits/stdc++.h>
#define int long long

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
int n, a, b;
vector<LL> v;
map<LL, int> mp;
/**********************************************/
void comb(vector<vector <LL> > &v){
  for(int i = 0;i <v.size(); i++){
    v[i][0]=1;
    v[i][i]=1;
  }
  for(int k = 1;k <v.size();k++){
    for(int j = 1;j<k;j++){
      v[k][j]=(v[k-1][j-1]+v[k-1][j]);
    }
  }
}

signed main(){
    cin >> n >> a >> b;
    v.resize(n);
    REP(i, n) cin >> v[i];

    sort(all(v), greater<LL>());
    REP(i, n) mp[v[i]]++;
    

    if(mp[v[0]] >= a){
        printf("%.6f\n", (double)v[0]);
        LL ans = 0;
        vector<vector<LL>> vec(mp[v[0]]+1, vector<LL>(mp[v[0]]+1, 0));
        comb(vec);
        FOR(i, a, b+1){
            if(i <= mp[v[0]]) ans += vec[mp[v[0]]][i];
        }
        cout << ans << endl;
    }else{
        double ave = 0;
        REP(i, a){
            ave += v[i];
        }
        ave /= a;
        printf("%.6f\n", ave);
        
        LL ans = 0;
        vector<vector<LL>> vec(mp[v[a-1]]+1, vector<LL>(mp[v[a-1]]+1, 0));
        comb(vec);
        LL k = 0;
        REP(i, n){
            if(i > a) break;
            if(v[a-1] == v[i]) k++;
        }
        ans += vec[mp[v[a-1]]][k-1];
        cout << ans << endl;

    }
}
