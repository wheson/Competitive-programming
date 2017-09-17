#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define llong long long
#define pb(a) push_back(a)
#define INF 999999999
using namespace std;
typedef pair<int, int> P;
typedef pair<llong, llong> LP;
typedef pair<int, P> PP;
typedef pair<llong, LP> LPP;

int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

int main(){
	string s;
	cin >> s;
	int abc[26] = {0};
	int nagasa = s.size();
	int cnt;	
	int min = 101;
	REP(i, 26){
		string ss = s;
		char c = 'a' + i;
		int naga = nagasa;
		bool flag = false;
		cnt = 0;
		if(ss.size() == 0) break;
		REPR(i, ss.size()){
			if(flag == true){
				break;
			}
			REP(i, ss.size() - 1){
				if(ss[i] != c && ss[i+1] == c){
					ss[i] = c;
				}
			}
			ss.erase(ss.end() - 1);
			REP(i, ss.size()){
				if(ss[i] != c){
					flag = false;
					break;
				}
				flag = true;
				
			}
			if(ss.find(c) == -1) break;
			++cnt;
		}
		if(flag == true){
			if(min > cnt){
				min = cnt;
			}
		}
	}

	cout << min << endl;
}
