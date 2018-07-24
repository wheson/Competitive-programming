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

bool f(string n){
    if((int)(n[n.size()-1] - '0')&1) return false;
    int sum = 0;
    REP(i, n.size()){
        sum += n[i] - '0';
    }
    if(sum % 3 != 0) return false;

    return true;
}

bool g(string n){
    int sum = 0;
    REP(i, n.size()){
        if(i % 2 == 0) sum += n[i] - '0';
        else sum -= n[i] - '0';
    }

    if(sum % 11 == 0) return true;
    return false;
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    string n;
    cin >> n;
    if(f(n)) cout << "yES" << endl;
    else cout << "nO" << endl;

    if(g(n)) cout << "yES" << endl;
    else cout << "nO" << endl;

}
