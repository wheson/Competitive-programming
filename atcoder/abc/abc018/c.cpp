#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <tuple>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <cstdio>
#include <bitset>
#include <climits>
#define REP(i, n) for(LL i = 0;i < n;i++)
#define REPR(i, n) for(LL i = n;i >= 0;i--)
#define FOR(i, m, n) for(LL i = m;i < n;i++)
#define FORR(i, m, n) for(LL i = m;i >= n;i--)
#define pb(a) push_back(a)
#define all(x) (x).begin(),(x).end()
#define INF (int)1e9
#define INFL (LL)1e15
#define MOD 1000000007
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

//#define int long long

/*************** using variables ***************/
int r, c, k;
vector<string> s;
int ans = 0;
/**********************************************/

signed main(){
    cin >> r >> c >> k;
    s.resize(r);
    REP(i, r) cin >> s[i];
    
    vector<vector<P>> renzoku;
    vector<vector<int>> list;
    renzoku.resize(r);
    list.resize(r);
    REP(i, r){
        renzoku[i].resize(c);
        list[i].resize(c);
    }

    REP(i, c){
        if(s[0][i] == 'o') renzoku[0][i].first = 1;
        else renzoku[0][i].first = 0;
        for(int j = 1; j < r; j++){
            if(s[j][i] == 'o') renzoku[j][i].first = renzoku[j-1][i].first + 1;
            else renzoku[j][i].first = 0;
        }

        if(s[r-1][i] == 'o') renzoku[r-1][i].second = 1;
        else renzoku[r-1][i].second = 0;
        for(int j = 1; j < r; j++){
            if(s[r-1-j][i] == 'o') renzoku[r-1-j][i].second = renzoku[r-1-j+1][i].second + 1;
            else renzoku[r-1-j][i].second = 0;
        }
    }
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            list[i][j] = min(renzoku[i][j].first, renzoku[i][j].second);
        }
    }
    for(int i = k-1; i <= r-k; i++){
        for(int j = k-1; j <= c-k; j++){
            bool flag = true;
            if(list[i][j] < k) flag = false;
            for(int l = 1; l < k; l++){
                if(list[i][j+l] < k-l) flag = false;
                if(list[i][j-l] < k-l) flag = false;
            }
            if(flag) ans++;
        }
    }
    cout << ans << endl;
}
