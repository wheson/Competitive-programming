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
	int a[101];
	int ranking[] = {399, 799, 1199, 1599, 1999, 2399, 2799, 3199};
	int rankcolor[] = {0, 0, 0, 0, 0, 0, 0, 0};
	cin >> n;
	int sum = 0;
	int freedom = 0;

	REP(i, n){
		int x;
		cin >> x;
		REP(j, 8){
			if(x <= ranking[j]){
				rankcolor[j] = 1;
				break;
			}
		}
		if(x >= 3200){
		freedom++;
		}
	
	}

	REP(i, 8){
		sum+=rankcolor[i];
	}

	cout << max(1 ,sum) << " " << sum + freedom << endl;
	
}
