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
#include <numeric>
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
int n;
vector<int> a;
LL ans = -INF;
int takahasi_score[55];
/**********************************************/

signed main(){
    cin >> n;
    a.resize(n);

    REP(i, n) cin >> a[i];
    
    REP(i, n){
        LL aoki_max_score = -INF, index;
        LL takahashi_score = 0;
        REP(j, n){
            LL aoki_score = 0;
            if(i != j){
                if(i < j){
                    REP(k, j-i+1){
                        if(k % 2 == 1){
                           aoki_score += a[k+i];
                           //cout << " +" << a[k+i];
                        }
                    }
                    //cout << endl;
                }else{
                    REP(k, i-j+1){
                        if(k % 2 == 1){
                            aoki_score += a[k+j];
                            //cout << " +" << a[k+j];
                        }
                    }
                    //cout << endl;
                }
                //cout << "i: " << i << " j: " << j << " aoki_score: " << aoki_score << endl;
                if(aoki_max_score < aoki_score){
                    index = j;
                    aoki_max_score = aoki_score;
                }
            }
        }
        if(i < index){
            REP(k, index-i+1){
                if(k % 2 == 0){
                   takahashi_score += a[k+i]; 
                }
            }
        }else{
            REP(k, i-index+1){
                if(k % 2 == 0){
                    takahashi_score += a[k+index];
                }
            }
        }
        ans = max(takahashi_score, ans);
        //cout << "i: " << i << " index: " << index << " aoki_max_score: " << aoki_max_score << " takahashi_score: " << takahashi_score << endl;
    }
    cout << ans << endl;
}
