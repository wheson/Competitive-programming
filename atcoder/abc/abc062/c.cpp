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
    LL h, w;
    cin >> h >> w;

    LL zentai = h * w;

    LL max = 0, mid = 0, min = 0;
    LL num = 0;
    LL numnum = 0; 

    if(w % 3 == 0){
        cout << 0 << endl;
        return 0;
    }

    if(h % 3 == 0){
        cout << 0 << endl;
        return 0;
    }
    
    if(h >= w){
        while(max < (zentai /*+ zentai % 3*/)/ 3){
            max += w;
            num++;
     }

        while(mid < ((zentai - max) / 2){
         mid += h - num;
         numnum++;
     }
    }else{
        while(max < (zentai /*+ zentai % 3*/)/ 3){
            max += h;
            num++;
     }

        while(mid < ((zentai - max) / 2){
         mid += w - num;
         numnum++;
     }
    }

    min = zentai - max - mid;
    /*
    max = (zentai + zentai % 3)/ 3;
    min = (zentai + zentai % 3)/ 3 - 
    */
    
    cout << max << " " <<  mid << " " << min << endl;
    cout << max - min << endl;
}