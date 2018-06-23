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

bool f(string s, vector<int> a){
    int n = s.size();

    REP(i, n){
        if(a[i] == 1){
            if(s[i] == 'o' && a[(i-1+n)%n] != a[(i+1+n)%n]) return false;
            if(s[i] == 'x' && a[(i-1+n)%n] == a[(i+1+n)%n]) return false;
        }else{
            if(s[i] == 'x' && a[(i-1+n)%n] != a[(i+1+n)%n]) return false;
            if(s[i] == 'o' && a[(i-1+n)%n] == a[(i+1+n)%n]) return false;
        }
    }
    return true;
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n; string s;
    cin >> n >> s;

    vector<int> a(n, 0);
    bool flag;
    a[0] = 0, a[1] = 0;
    for(int i = 1; i < n-1; i++){
        if(a[i]) a[i+1] = (s[i] == 'o' ? a[i-1] : (a[i-1]+1)%2); 
        else a[i+1] = (s[i] == 'x' ? a[i-1] : (a[i-1]+1)%2);
    }
    flag = f(s, a);
    
    if(flag){
        REP(i, n) cout << (a[i] ? 'S' : 'W');
        cout << endl;
        return 0;
    }
        
    a[0] = 1, a[1] = 0;
    for(int i = 1; i < n-1; i++){
        if(a[i]) a[i+1] = (s[i] == 'o' ? a[i-1] : (a[i-1]+1)%2); 
        else a[i+1] = (s[i] == 'x' ? a[i-1] : (a[i-1]+1)%2);
    }
    flag = f(s, a);
    
    if(flag){
        REP(i, n) cout << (a[i] ? 'S' : 'W');
        cout << endl;
        return 0;
    }

    a[0] = 0, a[1] = 1;
    for(int i = 1; i < n-1; i++){
        if(a[i]) a[i+1] = (s[i] == 'o' ? a[i-1] : (a[i-1]+1)%2); 
        else a[i+1] = (s[i] == 'x' ? a[i-1] : (a[i-1]+1)%2);
    }
    flag = f(s, a);
    
    if(flag){
        REP(i, n) cout << (a[i] ? 'S' : 'W');
        cout << endl;
        return 0;
    }

    a[0] = 1, a[1] = 1;
    for(int i = 1; i < n-1; i++){
        if(a[i]) a[i+1] = (s[i] == 'o' ? a[i-1] : (a[i-1]+1)%2); 
        else a[i+1] = (s[i] == 'x' ? a[i-1] : (a[i-1]+1)%2);
    }
    flag = f(s, a);
    
    if(flag){
        REP(i, n) cout << (a[i] ? 'S' : 'W');
        cout << endl;
        return 0;
    }

    cout << -1 << endl;
}
