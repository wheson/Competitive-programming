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
    int x, y;
    cin >> x >> y;
    int x1[] = {1,3,5,7,8,10,12};
    int x2[] = {4,6,9,11};
    int x3 = 2;
    
    int ansx , ansy;
    REP(i, 7){
        if(x == x1[i]) ansx = 1;
        if(y == x1[i]) ansy = 1;
    }

    REP(i, 4){
        if(x == x2[i]) ansx = 2;
        if(y == x2[i]) ansy = 2;
    }

    if(x == x3) ansx = 3;
    if(y == x3) ansy = 3;


    if(ansx == ansy){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}