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
const LL INFL = (LL)1e19;
const int MOD = 1e9 + 7;

// Rabin-Karp string search algorithm
class RollingHash{
    private:
      using ULL = unsigned long long;
      int n;
      const ULL mod = 1ULL << 63;
      const ULL base = 1000000007ULL;
      vector<ULL> hash, power;
    public:
      RollingHash(string s){
          n = s.size();
          hash.assign(n+1, 0ULL);
          power.assign(n+1, 0ULL);
          power[0] = 1ULL; 
          for(int i = 0; i < n; i++){
              power[i+1] = power[i] * base % mod;
              hash[i+1] = (s[i] + hash[i] * base) % mod;
          }
      }
      ULL GetHash(int l, int r){
          return ((hash[r] - hash[l] * power[r-l]) % mod + mod) % mod;
      }
};

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    vector<string> s(n);
    REP(i, n) cin >> s[i];

    vector<string> h(n, ""), w = s;
    REP(j, n){
        REP(i, n){
            h[j] = h[j] + s[i][j];
        }
    }
    REP(i, n){
        h[i] = h[i] + h[i] + h[i];
        w[i] = w[i] + w[i] + w[i];
    }

    vector<vector<bool>> check(n, vector<bool>(n, true));
    vector<RollingHash> hhash, whash;

    REP(i, n){
        hhash.pb(RollingHash(h[i]));
        whash.pb(RollingHash(w[i]));
    }

    REP(i, n){
        REP(j, n){
            REP(k, n-1){
                int sz = n - k;
                check[(i+n-k)%n][(j+n-k)%n] = check[(i+n-k)%n][(j+n-k)%n] 
                    && hhash[j].GetHash(i+1, i+1+sz) == whash[i].GetHash(j+1, j+1+sz);
                //cout << i << " " << j << " " << hhash[j].GetHash(i+1, i+1+sz) << " " << whash[i].GetHash(j+1, j+1+sz) << endl;
                //cout << (i+n-k)%n << " " << (j+n-k)%n << " " << hh[j][(i+1)%n][sz] << " " << ww[i][(j+1)%n][sz] << endl;
                //cout << (i+n-k)%n << " " << (j+n-k)%n << " " << h[j].substr(i+1, sz) << " " << w[i].substr(j+1, sz) << endl;
                //cout << "h: " << j << " " << i+1 << " w: " << i << " " << j+1 << endl;
            }
        }
    }
    int ans = 0;
    REP(i, n) REP(j, n){
        //cout << i << " " << j << " " << (check[i][j] ? 1 : 0) << endl;
        ans += check[i][j] ? 1 : 0;
    }
    cout << ans << endl;
}