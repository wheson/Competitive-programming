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

struct Cake{
    int w;
    int d;
    int cnt;
    Cake(int w, int d, int cnt) : w(w), d(d), cnt(cnt) {}
    bool operator< (const Cake& a) const{
        return (cnt == a.cnt ? w*d < a.w*a.d : cnt < a.cnt);
    }
};

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    while(1){
        int n, w, d;
        cin >> n >> w >> d;
        if(!n && !w && !d) break;
        vector<Cake> cake;
        cake.pb(Cake(w, d, 0));
        REP(i, n){
            int p, s;
            cin >> p >> s;
            p--;
            Cake now = cake[p];
            cake[p].cnt = INF;
            now.cnt = i;
            Cake next = now;
            s %= (now.w + now.d);
            if(s <= now.w){
                now.w = s;
                next.w = next.w-s;
            }else{
                now.d = s - now.w;
                next.d = next.w + next.d - s;
            }
            cake.pb(now);
            cake.pb(next);
            sort(all(cake));
        }
        vector<int> ans;
        REP(i, cake.size()) if(cake[i].cnt != INF) ans.pb(cake[i].d * cake[i].w);
        sort(all(ans));
        REP(i, n+1) cout << ans[i] << " \n"[i == n];
    }
}
