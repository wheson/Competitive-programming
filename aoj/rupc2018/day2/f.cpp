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
#include <limits.h>
#define REP(i, n) for(LL i = 0;i < n;i++)
#define REPR(i, n) for(LL i = n;i >= 0;i--)
#define FOR(i, m, n) for(LL i = m;i < n;i++)
#define FORR(i, m, n) for(LL i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define pb(a) push_back(a)
#define all(x) (x).begin(),(x).end()
#define INF (LL)1e15
#define MOD 1000000007
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
typedef pair<LL, LL> LP;
typedef pair<int, P> PP;
typedef pair<LL, LP> LPP;
int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

//#define int long long

/*************** using variables ***************/
/**********************************************/

signed main(){
    map<vector<int>, int> mp;
    int n;
    cin >> n;
    vector<int> amida = {0, 1, 2};
    mp[{0, 1, 2}] = 0;
    mp[{0, 2, 1}] = 0;
    mp[{1, 0, 2}] = 0;
    mp[{1, 2, 0}] = 0;
    mp[{2, 1, 0}] = 0;
    mp[{2, 0, 1}] = 0;
    REP(i, n){
        int w;
        cin >> w;
        vector<int> amida = {0, 1, 2};
        REP(i, w){
            int a;
            cin >> a;
            if(a == 0){
                swap(amida[0], amida[1]);
            }else if(a == 1){
                swap(amida[1], amida[2]);
            }
        }
        mp[amida]++;
    }

    bool flag = false;
    if(mp[{0, 1, 2}] >= 1) flag = true;
    else if(mp[{0, 2, 1}] >= 2 || mp[{1, 0, 2}] >= 2 || mp[{1, 2, 0}] >= 3 || mp[{2, 0, 1}] >= 3 || mp[{2, 1, 0}] >= 2) flag = true;

    if(!flag){
        if(mp[{1, 2, 0}] >= 1 && mp[{2, 0, 1}] >= 1) flag = true;
        else if(mp[{1, 2, 0}] == 0 && mp[{2, 0, 1}] == 0){
            cout << "no" << endl;
            return 0;
        }
        else{
            if(mp[{0, 2, 1}] + mp[{1, 0, 2}] + mp[{2, 1, 0}] >= 2){
                flag = true;
            }
        }

    } 
    if(flag) cout << "yes" << endl;
    else cout << "no" << endl;
    // デバッグ用
    /*
    cout << "{0, 1, 2}: " << mp[{0, 1, 2}] << endl;
    cout << "{0, 2, 1}: " << mp[{0, 2, 1}] << endl;
    cout << "{1, 0, 2}: " << mp[{1, 0, 2}] << endl;
    cout << "{1, 2, 0}: " << mp[{1, 2, 0}] << endl;
    cout << "{2, 1, 0}: " << mp[{2, 1, 0}] << endl;
    cout << "{2, 0, 1}: " << mp[{2, 0, 1}] << endl;
    */
}
