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
int x;
set<int> st;
/**********************************************/

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> x;
    st.insert(1);
    for(int a = 2; a <= sqrt(1000); a++){
        for(int b = 2; ; b++){
            if(pow(a, b) > 1000) break;
            st.insert(pow(a, b));
        }
    }
    auto itr = st.upper_bound(x);
    itr--;
    cout << *itr << endl;
}
