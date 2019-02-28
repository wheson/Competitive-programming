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
const LL INFL = (LL)1e18;
const int MOD = (int)1e9 + 7;

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    vector<int> a(k);
    REP(i, k) cin >> a[i];

    vector<string> s(n), s1, s2;
    REP(i, n) cin >> s[i];

    if(n == k){
        cout << endl;
        return 0;
    }

    map<int, int> mp;
    REP(i, k) mp[a[i]-1]++;
    REP(i, n){
        if(mp[i] > 0) s1.push_back(s[i]);
        else s2.push_back(s[i]);
    }

    string r = s1[0];
    vector<int> b1, b2;
    REP(i, s1.size()){
        int cnt = 0;
        for(int j = 0; j < r.size() && j < s1[i].size(); j++){
            if(r[j] == s1[i][j]) cnt++;
            else break;
        }
        b1.push_back(cnt);
    }
    REP(i, s2.size()){
        int cnt = 0;
        for(int j = 0; j < r.size() && j < s2[i].size(); j++){
            if(r[j] == s2[i][j]) cnt++;
            else break;
        }
        b2.push_back(cnt);
    }
    int b1min = *min_element(all(b1));
    int b2max = *max_element(all(b2));
    if(b2max < b1min){
        cout << r.substr(0, b2max + 1) << endl;
    }else{
        cout << -1 << endl;
    }
}