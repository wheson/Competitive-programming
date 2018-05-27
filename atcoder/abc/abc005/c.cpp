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
int t, n, m;
vector<int> a, b;
/**********************************************/

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> t >> n;
    a.resize(n);
    REP(i, n) cin >> a[i];
    cin >> m;
    b.resize(m);
    REP(i, m) cin >> b[i];
    
    if(n < m){
        cout << "no" << endl;
        return 0;
    }else{
        int j = 0;
        REP(i, m){
            bool flag = false;
            while(1){
                if(j >= n) break;
                if(a[j] <= b[i] && b[i] <= a[j]+t){
                    j++;
                    flag = true;
                    break;
                }else{
                    j++;
                }
            }
            if(!flag){
                cout << "no" << endl;
                return 0;
            }
        }
    }
    cout << "yes" << endl;
}
