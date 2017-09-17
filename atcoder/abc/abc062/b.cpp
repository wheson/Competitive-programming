#include <bits/stdc++.h>

//macro
#define REP(i, n) for(int i = 0; i < n; ++i)
#define REPR(i, n) for(int i = n; i >= 0; --i)
#define FOR(i, n, m) for(int i = m; i < n; ++i)
#define LL long long

using namespace std;

typedef pair<int, int> P;
typedef pair<LL, LL> LP;
typedef pair<int, P> PP;
typedef pair<LL, LP> LPP;

int main(){
    int h, w;
    cin >> h >> w;

    string a[101];
    REP(i, h){
        cin >> a[i];
    }

    REP(i, h){
        a[i].insert(a[i].begin(), '#');
        a[i].push_back('#');
    }

    REP(i, w + 2){
        cout << "#";
    }
    cout << endl;
    REP(i, h){
        cout << a[i] << endl;
    }
    REP(i, w + 2){
        cout << "#";
    }
    cout << endl;
}