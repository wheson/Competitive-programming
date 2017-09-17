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
	int n;
	string s, ans;
	cin >> n;
	cin >> s;
	ans = s;
	int zenka = 0;
	int kouka = 0;
	int ind = 0;
	REP(i, n){
		if(s[i] == '('){
			zenka++;
		}else if(s[i] == ')'){
			if(zenka != 0){
				zenka--;
			}else{
			ans.insert(ans.begin(), '(');	
			}
		}
	}
	REP(i, zenka){
				ans.push_back(')');
	}
	
	cout << ans << endl;
}