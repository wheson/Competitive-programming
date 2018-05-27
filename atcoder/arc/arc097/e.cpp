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

/*************** using variables **************/
int n;
vector<char> c;
vector<int> a;
vector<pair<char, int>> vec;
/**********************************************/

// O(n*2)
int check(char color){
    int num = 0;
    REP(i, n*2){
        pair<char, int> cur = vec[i];
        if(cur.first == color){
            if(num != cur.second) return num;
            num++;
        }
    }
    return num;
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> n;
    c.resize(2*n);
    a.resize(2*n);
    vec.resize(2*n);
    REP(i, n) {cin >> c[i] >> a[i]; a[i]--;}
    
    REP(i, n){
        vec[i] = pair<char, int>(c[i], a[i]);
    }

    int ans = 0;
    while(1){
        int num = check('W');
        cout << num << endl;
        if(num == n) break;

        for(int i = 0; i < 2*n; i++){
            pair<char, int> cur = vec[i];
            if(cur.first == 'W' && cur.second == num){
                for(int j = i; ; j--){
                    swap(vec[j], vec[j-1]);
                    ans++;
                    if(vec[j].first == 'W' && vec[j].second == num-1) break;
                }
                break;
            }
        }
        REP(i, 2*n){
            if(vec[i].first == 'W') cout << vec[i].second << " ";
        }
        cout << endl;
        string ok;
        cin >> ok;
    }

    while(1){
        int num = check('B');
        if(num == n) break;

        for(int i = 0; i < 2*n; i++){
            pair<char, int> cur = vec[i];
            if(cur.first == 'B' && cur.second == num){
                for(int j = i; ; j--){
                    swap(vec[j], vec[j-1]);
                    ans++;
                    if(vec[j].first == 'B' && vec[j].second == num-1) break;
                }
                break;
            }
        }
    }
    cout << ans << endl;
}
