#include <bits/stdc++.h>
#define int long long

using namespace std;
using LL = long long;
using P = pair<int, int>;
using Tapris = tuple<int, int, int>;

#define REP(i, n) for(LL i = 0; i < n; ++i)
#define FOR(i, a, n) for(LL i = a; i < n; ++i)
#define pb(a) push_back(a)
#define all(x) (x).begin(),(x).end()

const int INF = (int)1e9;
const LL INFL = (LL)1e15;
const int MOD = 1e9 + 7;

int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};


/*************** using variables ***************/
int n;
string s;
LL damage[500005];
/**********************************************/

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n >> s;
    damage[0] = 0;
    FOR(i, 1, 500001){
        damage[i] = damage[i-1] + i;
    }

    int first_cnt = -1;
    int end_cnt = 0;
    LL sum = 0;
    REP(i, s.size()){
        if(s[i] == 'A'){
            end_cnt++;
        }else{
            if(first_cnt == -1) first_cnt = end_cnt;
            else sum += damage[end_cnt];
            end_cnt = 0;
        }
    }
    if(first_cnt == -1){
        sum = (end_cnt*n+1) * end_cnt*n / 2;
    }else{
        sum *= n;
        sum += damage[first_cnt + end_cnt] * (n-1);
        sum += damage[first_cnt] + damage[end_cnt];
    }
    cout << sum << endl;
}

