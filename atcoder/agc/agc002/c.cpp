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
const LL INFL = (LL)1e18;
const int MOD = (int)1e9 + 7;

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, l;
    cin >> n >> l;
    vector<int> a(n);
    REP(i, n) cin >> a[i];

    int index = -1;
    REP(i, n-1){
        if(a[i] + a[i+1] >= l){
            index = i+1;
            break;
        }
    }

    if(index == -1){
        cout << "Impossible" << endl;
    }else{
        stack<int> st;
        for(int i = index; i >= 1; i--){
            st.push(i);
        }
        for(int i = index+1; i < n; i++){
            st.push(i);
        }
        cout << "Possible" << endl;
        while(!st.empty()){
            cout << st.top() << endl;
            st.pop();
        }
    }
}