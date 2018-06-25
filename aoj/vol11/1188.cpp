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

typedef string::const_iterator State;
class ParseError {
    public:
        static void inputError(void){
            cerr << "error!" << endl;
            exit(1);
        }
};

int number(State &begin){
    int ret = 0;
    while(isdigit(*begin)){
        ret *= 10;
        ret += *begin - '0';
        begin++;
    }
    return ret;
}

int calc(State &begin){
    if(*begin != '['){
        ParseError::inputError();
    }
    if(*(++begin) != '[') return (number(begin)/2 + 1);
    vector<int> a;
    while(*begin == '['){
        a.pb(calc(begin));
        begin++;
    }
    sort(all(a));
    int ans = 0;
    REP(i, a.size()/2+1) ans += a[i];
    return ans;
}

signed main(){
    int n;
    cin >> n;
    REP(i, n){
        string s;
        cin >> s;

        State begin = s.begin();
        int ans = calc(begin);
        cout << ans << endl;
    }
}
